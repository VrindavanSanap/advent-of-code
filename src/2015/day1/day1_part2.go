package main

import(
	"fmt"
	"os"
)
func main(){
	content, _ := os.ReadFile("./2015_day1.txt")
	floor :=0 
	for i, r := range content{
		if(r == '('){
		 	floor++
		}
		if(r == ')'){
		 	floor--
		}
		if(floor == -1){
			fmt.Println(i + 1)
			break
		}
	}
}