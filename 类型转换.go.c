package main

import (
	"fmt"
	"strconv"
)

func main(){
	str1 := "true"
	b1,ok := strconv.ParseBool(str1)  //返回值为bool + 错误码

	//判断是否发生错误？  发生错误ok =错误码   否则 error = nil
	if ok != nil {
		fmt.Println(ok)
		return
	}
	//未发生错误

	fmt.Printf("%T,%t\n",b1,b1)

	s1 := strconv.FormatBool(b1)
	fmt.Printf("%T,%s\n",s1,s1)


	// str  to  int    Atoi
	str2 :="110"
	i1,ok := strconv.ParseInt(str2,10,64) //  str2  进制  ,多少位
	if ok != nil{
		fmt.Println(ok)
		return
	}
	fmt.Println(i1)

	ss2 := strconv.FormatInt(i1,10)
	fmt.Printf("%T,%s\n",ss2,ss2)
	ss3 :="-40"
	i2,ok:= strconv.Atoi(ss3)// Atoi  需要接受 转换的错误码
	fmt.Println(i2,ok)
	ss4 := strconv.Itoa(i2) // ItoA  不需要准备转换的错误码
	fmt.Printf("%T,%s\n",ss4,ss4)

}
