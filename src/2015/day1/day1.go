package main

import(
	"fmt"
	"os"
)
func main(){
	content, _ := os.ReadFile("./2015_day1.txt")
	floor :=0 
	for _, r := range content{
		if(r == '('){
		 	floor++
		}
		if(r == ')'){
		 	floor--
		}
	}
		fmt.Println(floor)
}