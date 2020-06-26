package main

import (
	"fmt"
	"sort"
)

func main(){
	var map1 = map[int]string{1:"haha",2:"hehe",3:"yingyingying"}
	fmt.Println(map1)
	v,ok := map1[4]
	fmt.Println(v," ", ok)//ok= fasle  所以 v的零值为""
	map1[4] ="memeda"
	fmt.Println(map1)

	delete(map1, 10)
	delete(map1,3)
	fmt.Println(map1)

	//  遍历发现 map是 无序的
	for key, value := range map1{
		fmt.Println(key, value)
	}

	//我们发现 ，假如 key不连续 ，那么就有问题
	values := []string{}
	for i:=1; i<=len(map1)+1; i++{
		fmt.Println(i,"--->",map1[i])
		values = append(values, map1[i])
	}

	sort.Strings(values)
	fmt.Println(values)
}
