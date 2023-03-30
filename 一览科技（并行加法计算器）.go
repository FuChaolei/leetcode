//go:build ignore

package main

import (
	"fmt"
	//"runtime"
	"sync"
	"time"
)

var sum int
var mu sync.Mutex

func add(start int, len int) {
	for i := start; i < start+len; i++ {
		mu.Lock()
		sum += i
		mu.Unlock()
	}
}
func main() {
	sum = 0
	start := 1
	for i := 1; i <= 1000; i++ {
		go add(start, 100)
		start += 100
	}
	//fmt.Println(runtime.NumGoroutine())
	time.Sleep(1 * time.Second)
	fmt.Println(sum)
}
