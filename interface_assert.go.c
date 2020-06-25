package main

import (
	"fmt"
	"math"
)

type Circle struct{
	path float64
}

type Square struct{
	path int
}

type AA interface {
	Area()
	CLong()
}
func (s Square)Area(){
	fmt.Println("Square Area is:",s.path * s.path)
}
func (s Square)CLong(){
	fmt.Println("Square Long is:",s.path * 4)
}
func (c Circle)Area(){
	fmt.Println("Circle Area is:",c.path * c.path * math.Pi)
}
func (c Circle)CLong(){
	fmt.Println("Circle long is:",c.path * 2 * math.Pi)
}

func getAssert(a AA){
	if ret,ok :=a.(Circle); ok{
		fmt.Println("it is Circle, path is",ret.path)
	}else if ret, ok := a.(Square);ok{
		fmt.Println("it  is Square, path is ",ret.path)
	}else if ret,ok :=a.(*Circle); ok{
		fmt.Println("it is Circle, path is",(*ret).path)
	}else if ret,ok :=a.(*Square); ok{
		fmt.Println("it  is Square, path is ",ret.path)
	}else{
		fmt.Println("i don't know what type a is")
	}
}

func testAssert2(a AA){
	switch ret := a.(type){  //a.(type) 只能用在 switch 语句中
	case Circle:
		fmt.Println("Circle",ret.path)
	case Square:
		fmt.Println("Square",ret.path)
	case * Circle:
		fmt.Println("Circle",ret.path)
	case * Square:
		fmt.Println("Square",ret.path)
	default:
		fmt.Println("i don't what type it is")
	}
}


func testAssert(a AA){
	getAssert(a)
	a.Area()
	a.CLong()
}

func main(){
	c := Circle{4}
	s := Square{4}
	d := &Circle{3}
	e := &Square{3}
	testAssert2(e)
	testAssert(d)
	testAssert(c)
	testAssert(s)


	testAssert2(e)
	testAssert2(d)
	testAssert2(c)
	testAssert2(s)
}
