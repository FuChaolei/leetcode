//go:build ignore

package main

import "fmt"

type Abstractfruit interface {
	ShowName()
}
type Apple struct {
}

func (apple *Apple) ShowName() {
	fmt.Println("I'm apple")
}

type Banana struct {
}

func (banana *Banana) ShowName() {
	fmt.Println("I'm banana")
}

type Abstractfactory interface {
	Createfruit() Abstractfruit
}
type Applefactory struct {
}

func (applefactory *Applefactory) Createfruit() Abstractfruit {
	return new(Apple)
}

type Bananafactory struct {
}

func (bananafactory *Bananafactory) Createfruit() Abstractfruit {
	return new(Banana)
}
func main() {
	var factory Abstractfactory
	var fruit Abstractfruit
	factory = new(Applefactory)
	fruit = factory.Createfruit()
	fruit.ShowName()
	factory = new(Bananafactory)
	fruit = factory.Createfruit()
	fruit.ShowName()
}
