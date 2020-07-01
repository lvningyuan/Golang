package main

import (
	"fmt"
	"reflect"
)

func main(){
	 var num float64 =1.23
	 fmt.Println("num->",num)
	 pointer:= reflect.ValueOf(&num)
	 newValue := pointer.Elem()// 获取指针指向的value对象
	 fmt.Println("newValue -> ",newValue)
	 fmt.Println("newValue类型-->",newValue.Type())
	 fmt.Println("newValue种类-->",newValue.Kind())
	 fmt.Println("newValue是否可以修改对象：",newValue.CanSet())
	 newValue.SetFloat(3.14)
	 fmt.Println("newValue is ->",newValue)
	 fmt.Println("num is->",num)

}