function is_multiple_of_3(number)
    return number % 3 == 0
end

function is_multiple_of_5(number)
    return number % 5 == 0
end 

function fizz_buzz()
    for counter=1,100 do 
        if is_multiple_of_3(counter) and is_multiple_of_5(counter) then
            print("FizzBuzz")
        elseif is_multiple_of_3(counter) then
            print("Fizz")
        elseif is_multiple_of_5(counter) then
            print("Buzz")
        else
            print(counter)
        end
    end
end

fizz_buzz()