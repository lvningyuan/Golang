package main

import "fmt"

type people struct{
	name string
}

type  person = people

type  puiple struct {
	person
	people
}

func(p person) show1(){
	fmt.Println(p.name)
}

func (p people) show2(){
	fmt.Println(p.name)
}

func main(){
	var s puiple
	s.person.name ="小明"
	s.people.name ="明明"
	println(s.person.name)
	println(s.people.name)
	fmt.Printf("s.people's addresss is :%p\n",&(s.people.name))
	fmt.Printf("s.person's addresss is :%p\n",&(s.person.name))
//	testShow(s)
}
/*
type myInt int
type  INT = int
func main(){
var a int =4
var a1 myInt = 5
// a = a1// 不能隐式类型转换 ，但是可以强制类型转换
a = int (a1)
println(a)

var cc INT = 10
fmt.Printf("%T\n",cc)
}
 */
