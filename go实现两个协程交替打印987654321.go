//go:build ignore

package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup
var ca chan int

func main() {
	wg = sync.WaitGroup{}
	ca = make(chan int)
	wg.Add(2)
	go print1()
	go print2()
	wg.Wait()
}
func print1() {
	for i := 9; i >= 1; i-- {
		ca <- 1
		if i%2 == 1 {
			fmt.Println(i)
		}
	}
	wg.Done()
}
func print2() {
	for i := 9; i >= 1; i-- {
		<-ca
		if i%2 == 0 {
			fmt.Println(i)
		}
	}
	wg.Done()
}
