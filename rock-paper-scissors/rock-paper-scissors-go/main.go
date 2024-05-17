package main

import (
	"fmt"
	"math/rand"
	"os/exec"
	"os"
	"bufio"
	"strings"
	"time"
)

const (
	ROCK     = iota
	PAPER    = iota
	SCISSORS = iota

	WIN  = iota
	LOSE = iota
	TIE  = iota
)

type Score struct {
	Wins   int
	Losses int
	Ties   int
}

func GetPlayerInput() int {
	var selection int

	for {
		fmt.Println("[1] - Rock, [2] - Paper, [3] - Scissors")
		fmt.Scan(&selection)

		if selection > 0 && selection < 4 {
			break
		}
	}
	
	return selection - 1
}

func GetComputerChoice() int {
	return rand.Intn(3) // 0 to 2 
}

func ClearScreen() {
	c := exec.Command("clear")
	c.Stdout = os.Stdout
	c.Run()
}

func GameLogic(curr_score *Score, computer_choice int, player_choice int) int {
	// Refactor later
	if player_choice == computer_choice { 
		curr_score.Ties += 1 
		return TIE
	} else if player_choice == ROCK && computer_choice == SCISSORS { 
		curr_score.Wins += 1
		return WIN
	} else if player_choice == ROCK && computer_choice == PAPER { 
		curr_score.Losses += 1 
		return LOSE
	} else if player_choice == PAPER && computer_choice == ROCK { 
		curr_score.Wins += 1 
		return WIN
	} else if player_choice == PAPER && computer_choice == SCISSORS { 
		curr_score.Losses += 1 
		return LOSE
	} else if player_choice == SCISSORS && computer_choice == PAPER { 
		curr_score.Wins += 1
		return WIN
	} else if player_choice == SCISSORS && computer_choice == ROCK { 
		curr_score.Losses += 1 
		return LOSE
	}

	return 0
}

func main() {
	var curr_score      Score
	var player_choice   int
	var computer_choice int
	var answer          string
	var result          int

	ClearScreen()
	
	fmt.Println("Welcome to Rock Paper Scissors!")
	fmt.Println("Press enter to begin...")

	bufio.NewReader(os.Stdin).ReadBytes('\n')

	for {
		ClearScreen()
		fmt.Println("Total Score:")
		fmt.Printf("	Wins %d | Losses %d | Ties %d\n", curr_score.Wins, curr_score.Losses, curr_score.Ties)
		fmt.Println("\nGet ready...\n")
	
		player_choice   = GetPlayerInput()
		computer_choice = GetComputerChoice()
		result = GameLogic(&curr_score, player_choice, computer_choice)

		ClearScreen()
		
		fmt.Println("Rock...")
		time.Sleep(500 * time.Millisecond)
		fmt.Println("Paper...")
		time.Sleep(500 * time.Millisecond)
		fmt.Println("Scissors...")
		time.Sleep(500 * time.Millisecond)
		fmt.Println("Shoot!")
		time.Sleep(500 * time.Millisecond)

		if result == TIE {
			fmt.Println("Its a tie!")
		} else if result == WIN {
			fmt.Println("You win! Good job!")
		} else {
			fmt.Println("You lose!")
		}

		fmt.Println("Would you like to play again?")
		fmt.Scan(&answer)

		if strings.ToLower(answer) == "no" {
			break
		}
	}
	ClearScreen()
	fmt.Println("Final Score:")
	fmt.Printf("	Wins %d | Losses %d | Ties %d\n", curr_score.Wins, curr_score.Losses, curr_score.Ties)
	fmt.Println("Thanks for playing!")
}
