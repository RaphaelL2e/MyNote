# 注解

## 一、概述

代码里的特殊标记。可以在编译、类加载、运行时被读取，并执行相应的处理。

代码分析工具、开发工具和部署工具可以通过这些补充信息进行验证或者进行部署。



一定程度上： **框架 = 注解 + 反射 + 设计模式**

# 二、annotation的使用实例

## 1.文档相关的注解

## 2. 编译时进行格式检查(JDK内置的三个基本注解)

- @Overridde 重写

- @Deprecated 表示修饰的元素已经过时

- @SuppressWarnings 抑制编译器警告

## 3.跟踪代码依赖性，实现替代配置文件功能

- **@WebServlet** ，使得不再需要在web.xml文件中进行servlet的部署
- **@Transactional** ，Spring框架中关于事物的管理

# 三、自定义注解

如果没有成员，表明是一个标识作用

```java
package com.leeyf.annotation;



/**
 * @author:leeyf
 * @create: 2019-08-12 16:04
 * @Description:我的自定义注解
 */
public @interface MyAnnotation {
    //成员变量 8种基本数据类型、String、Class等
    String value() default "hello";
}
```

# 四、四个元注解的使用

| 元注解(现有注解进行解释说明) | 作用                                                         |
| ---------------------------- | ------------------------------------------------------------ |
| Retention                    | 只用于修饰一个annotation定义，指明所修饰annotation的生命周期，@Retention包含一个 RetentionPolicy类型的成员变量，使用时必须为该Value成员变量指定值 |
| Target                       | 用于指定被修饰的Annotation能用于修饰哪些程序元素。包含一个成员变量value |
| Documented                   | 用于指定被该元Annotation修饰的Annotation类将被javadoc工具提取成文档。默认情况下javadoc是不包括注解的。<br />**定义为Documented的注解必须设置Retetion值为RUNTIME. |
| Inherited                    | 被它修饰的Annotation将具有继承性。某个类使用了被Inherited修饰的注解，子类自动的使用该注解 |

元数据的 理解：

- String name = "leeyf";

- 对现有数据修饰

### **@Retention**

RetentionPolicy.SOURCE: 在源文件中有效，编译器直接丢弃这种策略的注释

RetentionPolicy.CLASS:在class文件中有效，当运行java程序时，JVM不会保留注解，这是默认值

RetentionPolicy.RUNTIME:在运行时有效，当运行java程序时，JVM会保留注释，程序可以通过反射来获取该注解

# 五、jdk8 中 注解新特性： 可重复注解、类型注解

### 1.可重复注解

```java
package com.leeyf.annotation;

import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import static java.lang.annotation.ElementType.FIELD;
import static java.lang.annotation.ElementType.TYPE;

/**
 * @author:leeyf
 * @create: 2019-08-12 19:51
 * @Description:
 */
@Retention(RetentionPolicy.RUNTIME)
@Target({FIELD,TYPE})
public @interface MyAnnotations {
    MyAnnotation[] value();
}
```

```java
package com.leeyf.annotation;


import java.lang.annotation.*;

import static java.lang.annotation.ElementType.FIELD;
import static java.lang.annotation.ElementType.TYPE;

/**
 * @author:leeyf
 * @create: 2019-08-12 16:04
 * @Description:我的自定义注解
 */
@Target({FIELD,TYPE})
@Inherited
@Repeatable(MyAnnotations.class)
@Retention(RetentionPolicy.RUNTIME)
public @interface MyAnnotation {
    //成员变量 8种基本数据类型、String、Class等
    String value() default "hello";
}
```

@Repeatable 成员值为 MyAnnotations.class 

MyAnnotation 的 target和retention 相同

### 2.类型注解

```java
/**
 * Type parameter declaration
 *表示该注解能写在类型变量的声明语句中
 * @since 1.8
 */
ElementType.TYPE_PARAMETER,

/**
 * Use of a type
 *表示该注解能写在使用类型的任何语句中
 * @since 1.8
 */
ElementType.TYPE_USE
```

```java
class Generic<@MyAnnotation T>{
    
    public void show() throws @MyAnnotation RuntimeException{
        ArrayList<@MyAnnotation String> list = new ArrayList<>();
        int num = (@MyAnnotation int) 10L;
    }
}
```
