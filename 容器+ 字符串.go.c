package main

import (
	"fmt"
	"strings"
)

func main() {
	/*
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
	*/

	/*
		map1 := make(map[string]string)
		map1["name"] = "张三"
		map1["age"] = "18"
		map1["身高"] ="180"
		map1["gender"] ="woman"
		map2 := make(map[string]string)
		map2["name"] = "李四"
		map2["age"] = "20"
		map2["身高"] ="190"
		map2["gender"] ="woman"
		map3 := make(map[string]string)
		map3["name"] = "王豆"
		map3["age"] = "22"
		map3["身高"] ="158"
		map3["gender"] ="woman"

		ret1 := make([]map[string]string, 0, 3)// 创建容量为3的空slice
		ret1 = append(ret1,map1)
		ret1 = append(ret1,map2)
		ret1 = append(ret1,map3)

		fmt.Println(ret1)
	*/
	/*
	s1 := "hello"
	s2 := `hello world`
	fmt.Println(s1, " ", s2)
	fmt.Println(len(s1), " ", len(s2)) //返回所占字节的总长度！！并不是字符的个数
	s3 := "hell王"
	fmt.Println(len(s1), " ", len(s3)) //可见 中文字符占3个字节
*/
	ch := []byte{'A', 'B', 'C', 'D'}//slice
	str1 := string(ch)
	fmt.Println(str1)
	ch1 := []byte{65, 66, 67, 68}//slice
	str2 := string(ch1)
	fmt.Println(str2)
	ch3 :=`hello world`
	fmt.Println(strings.IndexAny(ch3,"abcde"))

	ss1:=[]string{"aaa","bbb","CCC","DDD"}
	sss1:=strings.Join(ss1,"*")
	fmt.Println(sss1)
	ss2:=[]string{"aaa","bbb","CCC","DDD"}
	fmt.Println(strings.Join(ss2,"+"))

	sssss1 := strings.Split(sss1,"*") //Split 返回值是一个切片
	fmt.Println(sssss1)
	fmt.Printf("%T",sssss1)
	fmt.Println()

	sssssss1 :=strings.Repeat(sss1,3)
	fmt.Println(sssssss1)

	//切片操作
	sss1 ="helloworld" //合法
	//sss1[1] ='o'// 非法
	s10 := sss1[:5]  //左闭右开
	fmt.Println(s10)
}