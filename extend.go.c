package main
 type Person struct{
 	name string
 	age  int
 }
type Student struct{
	Person // 匿名结构体  模拟实现 继承
	school string
}

func  method1()

func main(){
	s1 := new(Student)
	s1.name = "海绵宝宝"//提升字段
	s1.age = 18		  // 提升字段
	s1.school = "北京大学"
	println(s1.name," ", s1.age," ", s1.school)
	s2 := Student{Person{"派大星",17}, "XPU"}
	println(s2.name," ",s2.age," ", s2.school)//' ' 不能表示空格代表32ASCII
	s3 := Student{Person:Person{name:"擎天柱",age:14}, school:"地球"}
	println(s3.name," ",s3.age," ", s3.school)
	s4 := Student{Person{"大黄蜂",13}, "泰斯坦"}
	println(s4.name," ",s4.age," ",s4.school)




}
