const path = "./2015_day2.txt";
const file = Bun.file(path);
const text = await file.text()
const lines = text.trim().split("\n");

function ribbon_len(height:number, width:number, length:number):number {
	let len = (height + width + length) * 2;
	len -= Math.max(height, width, length) * 2;
	len += (height * width * length);
	return len;
}

var total_area = 0;
for (const line of lines) {
	const [h, w, l]= line.split("x").map(Number);
	total_area += ribbon_len(h, w, l);
}
console.log(total_area);