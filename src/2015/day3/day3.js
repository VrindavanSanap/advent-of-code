const path = "./2015_day3.txt"
const file = Bun.file(path)
const text = await file.text();
let x = 0;
let y = 0;
const s = new Set();
for (let i = 0; i < text.length; i++) {

	if (text[i] == '<') {
		x -= 1;
	}
	if (text[i] == '>') {
		x += 1;
	}
	if (text[i] == '^') {
		y += 1;
	}
	if (text[i] == 'v') {
		y -= 1;
	}
	s.add(JSON.stringify({ x, y }));

};
console.log(s.size)