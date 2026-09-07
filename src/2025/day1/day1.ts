// const text = await file.text()

const file = Bun.file("./2025_day1.txt");
const text = await file.text()

let position = 50;
let sum = 0;
function mod(a:number, b:number):number {
	let r = a % b;
	if (r < 0) {
		r += b;
	}
	return r;
}
for (const line of text.trim().split("\n")) {
	const direction = line[0]
	const distance = parseInt(line.slice(1), 10);
	if (direction == 'L') {
		position = mod(position - distance, 100)
	} else if (direction == 'R') {
		position = mod(position + distance, 100)
	}
	if (position == 0) {
		sum++;
	}
}
console.log(sum);