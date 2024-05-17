// Gets a random languange from the ./list.txt

function load_list(path) {
	const fs = require("fs"); // Library

	const list_string = fs.readFileSync( // load file
		path,
		{ encoding: 'utf8', flag: 'r' }
	);

	let list = list_string.split(", ").map((item) => {
		return item.replace("\n", "");
	}); // turn into list

	return list;
}

function select_random(list) {
	return list[Math.floor(Math.random() * list.length)];
}

const list = load_list("./list.txt");
console.log("Languange selected was: " + select_random(list));