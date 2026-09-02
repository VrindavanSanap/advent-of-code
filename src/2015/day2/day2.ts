const path = "./2015_day2.txt";
const file = Bun.file(path);
const text = await file.text()
const lines = text.trim().split("\n");

function surface_area(height:number, width:number, length:number):number {
	let side_1 = height * width;
	let side_2 = length * width;
	let side_3 = length * height;
	let area = 2 * (side_1 + side_2 + side_3)
	let slack = Math.min(side_1, side_2, side_3);
	area += slack;
	return area;
}

var total_area = 0;
for (const line of lines) {
	const [h, w, l]= line.split("x").map(Number);
	total_area += surface_area(h, w, l);
}
console.log(total_area);