# 交互信息说明
- 版本：V0.1.0
- 时间：2019-07-22

## 基本的说明
* 所有的中文采用UTF-8格式编码
* 响应状态码如下:

|状态码|说明|
|--|--|
|10|请求成功|
|20|由于网络原因请求失败|
|30|请求失败|
* 时间表:

|星期|代码|时间段|代码|
|--|--|--|--|
|星期一|1|8.00-10.00|1|
|星期二|2|10.00-12.00|2|
|星期三|3|14.00-16.00|3|
|星期四|4|16.00-18.00|4|
|星期五|5|19.00-21.00|5|
|星期六|6|
|星期天|7|

每个说明时段的数据格式采用第一位星期，第二位时间段(方便你解析)
例：星期一16.00-18.00和星期二8.00-10.00
```json
{
	"time":
	[
	  14,
	  21
	]
}
```

## 获取用户是否注册
### 请求信息
|项目|类型|键名|说明|
|--|--|--|
|请求方式|POST|
|url|预留|
|unionid|string|unionid||


## 个人信息注册
### 请求信息
|项目|类型|键名|说明|
|--|--|--|
|请求方式|POST|
|url|预留|
|类型|int|type|1是学生，2是老师，预留|
|姓名|string|name|
|年龄|int|age|判断范围|
|性别|int|sex|1是男性，2是女性，预留|
|手机号|string|phone|
|出生日期|string|birthday|yyyy-mm-dd|
|学校|string|university|只有老师填写|
|地区|string|region|
|科目|string|course|只有老师填写|
|审核过程|int|verify|1为待审核，2为审核中，3为审核通过|

**json文件样例**
```json
{
	"type": 1,
	"name": "张抗抗",
	"age": 21,
	"sex": 1,
	"phone": "18012345678",
	"birthday": "1999-01-01",
	"university": "中山大学",
	"region": "北京",
	"course": [
		"语文",
		"数学"
	],
	"verify": 1
}
```
### 响应信息
|项目|类型|键名|说明|
|--|--|--|--|
|请求方式|POST|
|url|预留|
|响应码|int|status|响应码表格|
|响应信息|string|response|响应成功OK，失败说明原因|
|学生或者老师id|int|people_id|学生或者老师的唯一id|

**json文件样例**
```json
{
	"status": 10,
	"response": "OK",
	"people_id": 1888992
}
```

## 课程发布

### 请求信息

|项目|类型|键名|说明|
|--|--|--|--|
|课程类型|string|course|一次发布一门课|
|课程名称|string|course_name|
|老师姓名|string|teacher_name|
|老师id|int|people_id|
|时间|int[]|time|每周七天，每天五个时间段,多个时段采用数组发送|
|课程简介|string|introduction|小于100字|

```json
{
	"course": "语文",
	"course_name": "精品数学课",
	"teacher_name": "张抗抗",
	"people_id": 172342
	"time": [
		14,
		21
	],
	"introduction": "这是一个xxx的课程，谢谢！"
}
```
### 响应信息

|项目|类型|键名|说明|
|--|--|--|--|
|响应码|int|status|响应码表格|
|响应信息|string|response|响应成功OK，失败说明原因|
|课程id|int|course_id|课程id|

**json文件样例**
```json
{
	"status": 10,
	"response": "OK",
	"course_id": 12345
}
```

## 课程查询
### 请求信息
|项目|类型|键名|说明|
|--|--|--|--|
|请求方式|POST|
|url|预留|
|输入的关键字|string|content|


**json文件样例**
```json
{
	"content": "张抗抗"
}
```
### 响应信息
按照用户的关键字对人名，课程地区，课程简介进行匹配

|项目|类型|键名|说明|
|--|--|--|--|
|响应码|int|status|响应码表格|
|响应信息|string|response|响应成功OK，失败说明原因|
|课程信息|class|info|自定义一个class类|

```json
{
	"status": 10,
	"response": "OK",
	"class": [{
			"course_id": 165243,
			"course_name": "精品数学课",
			"teacher_name": "张抗抗",
			"introduction": "这是一个xxx的课程，谢谢！",
			"time": [
				14,
				21
			]
		},
		{
			"course_id": 123243,
			"course_name": "垃圾数学课",
			"teacher_name": "张抗抗",
			"introduction": "这是一个xxx的课程，谢谢！",
			"time": [
				14,
				21
			]
		}
	]
}
```

## 选课

### 请求信息
|项目|类型|键名|说明|
|--|--|--|--|
|请求方式|POST|
|url|预留|
|课程id|int|course_id|
|学生id|int|people_id|

```json
{
	"course_id": 123456,
	"people_id": 234567
}
```

### 响应信息
|项目|类型|键名|说明|
|--|--|--|--|
|响应码|int|status|响应码表格|
|响应信息|string|response|响应成功OK，失败说明原因|
|订单id|int|order_id|
```json
{
	"status": 10,
	"response": "OK",
	"order_id": 12345
}
```
