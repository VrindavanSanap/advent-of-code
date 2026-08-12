const path = "./2015_day1.txt"
const file = Bun.file(path)
const text = await file.text();
let floor_n = 0;
for (let i = 0; i < text.length; i++){
	if (text[i] == '(') {
		floor_n++;
	} else if (text[i] == ')') {
		floor_n--;
	}
}
console.log(`Floor no:${floor_n}`);