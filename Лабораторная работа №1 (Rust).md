
# Rust - Лабораторная работа № 1
## Задание 1
**Постановка задачи:**
Напишите программу, которая запрашивает у пользователя имя и выводит на экран приветственное сообщение с использованием этого имени.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
name|String|Вводимое имя

**Код программы:**
```Rust
fn main() -> std::io::Result<()>
{
	let mut name = String::new();

	println!("What is your name?");
	std::io::stdin().read_line(&mut name)?;
	print!("Hello, {name}!");

	Ok(())
}
```
**Результат:**
```
What is your name?
>>	Egor
Hello, Egor
```
___
## Задание 2
**Постановка задачи:**
Создайте переменную типа целое беззнаковое число и выведите ее значение на экран. Явно укажите тип переменной. Затем измените значение переменной и снова выведите его.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
some_num|u8|Просто переменная

**Код программы:**
```Rust
fn main()
{
	let mut some_num: u8;	// пишем "mut", чтобы можно было изменять переменную

	some_num = 192;
	println!("1) some_num = {some_num}");

	some_num = 11;
	print!("2) some_num = {some_num}");
}
```
**Результат:**
```
1) some_num = 192
2) some_num = 11
```
___
## Задание 3
**Постановка задачи:**
Напишите функцию, которая принимает строку и возвращает ее длину (количество символов). Затем вызовите эту функцию с различными строками.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
length|usize|Функция, возвращающая длину строки

**Код программы:**
```Rust
fn main()
{
	println!("Length of opop: {:?}", length("opop"));
	println!("Length of Babuin: {:?}", length("Babuin"));
	print!("Length of Joposranchik: {:?}", length("Joposranchik"));
}


fn length(some_string: &str) -> usize
{ return some_string.len(); }
```
**Результат:**
```
Length of opop: 4
Length of Babuin: 6
Length of Joposranchik: 12
```
___
## Задание 4
**Постановка задачи:**
Задайте структуру Car с полями brand, model и year, и создайте несколько экземпляров этой структуры. Выведите информацию о каждой машине на экран.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
fcar|struct Car|Некоторый экземпляр структуры Car
scar|struct Car|Некоторый экземпляр структуры Car
tcar|struct Car|Некоторый экземпляр структуры Car

**Код программы:**
```Rust
fn main()
{
	let fcar = Car
	{
		brand: "Opop".to_string(),
		model: "2002ui".to_string(),
		year: 2006
	};
	let scar = Car
	{
		brand: "Opop".to_string(),
		model: "CH2002ui".to_string(),
		year: 2011
	};
	let tcar = Car
	{
		brand: "Spoker".to_string(),
		model: "20BOR".to_string(),
		year: 1911
	};

	println!("brand={:?} model = {:?} year={:?}", fcar.brand, fcar.model, fcar.year);
	println!("brand={:?} model = {:?} year={:?}", scar.brand, scar.model, scar.year);
	println!("brand={:?} model = {:?} year={:?}", tcar.brand, tcar.model, tcar.year);
}


struct Car
{
	brand: String,
	model: String,
	year: u16
}
```
**Результат:**
```
brand="Opop" model = "2002ui" year=2006
brand="Opop" model = "CH2002ui" year=2011
brand="Spoker" model = "20BOR" year=1911
```
___
## Задание 5
**Постановка задачи:**
Напишите программу, которая запрашивает у пользователя число 𝑁 и выводит на экран 𝑁­-ое число Фибоначчи. Используйте рекурсию для решения этой задачи.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
result|u32|Результат функции

**Код программы:**
```Rust
fn main()
{	
	let result: u32;
	result = fib(8);

	print!("{:?}", result);
}


fn fib(n: u32) -> u32
{
	if n == 1 || n == 2 { return 1; }
	return fib(n - 1) + fib(n - 2);
}
```
**Результат (здесь для N = 8):**
```
21
```
___
## Задание 6
**Постановка задачи:**
Реализуйте перечисление DayOfWeek для дней недели. Напишите функцию, которая принимает день недели и возвращает следующий день. Обработайте случаи перехода на следующий день недели, если текущий день – воскресенье.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
DayOfWeek|enum|Перечисление дней недели
day|DayOfWeek|Текущий день
result|DayOfWeek|Следующий день

**Код программы:**
```Rust
fn main()
{	
	let day = DayOfWeek::Sunday;
	let result = next_day(day);

	match result
	{
		DayOfWeek::Monday => print!("Monday"),
		DayOfWeek::Tuesday => print!("Tuesday"),
		DayOfWeek::Wednesday => print!("Wednesday"),
		DayOfWeek::Thursday => print!("Thursday"),
		DayOfWeek::Friday => print!("Friday"),
		DayOfWeek::Saturday => print!("Saturday"),
		DayOfWeek::Sunday => print!("Sunday")
	};
}


fn next_day(day: DayOfWeek) -> DayOfWeek
{
	let result = match day
	{
		DayOfWeek::Monday => DayOfWeek::Tuesday,
		DayOfWeek::Tuesday => DayOfWeek::Wednesday,
		DayOfWeek::Wednesday => DayOfWeek::Thursday,
		DayOfWeek::Thursday => DayOfWeek::Friday,
		DayOfWeek::Friday => DayOfWeek::Saturday,
		DayOfWeek::Saturday => DayOfWeek::Sunday,
		DayOfWeek::Sunday => DayOfWeek::Monday
	};

	return result;
}


enum DayOfWeek
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
}
```
**Результат (для Sunday):**
```
Monday
```
___
## Задание 7
**Постановка задачи:**
Создайте структуру Product с полями name, price и category, а также перечисление (enum) Category для категорий товаров. Напишите метод для вывода информации о продукте и ассоциированную функцию для подсчета общей суммы товаров в заданной категории из массива продуктов.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
Product::init|Self|Функция для инициализации объекта структуры
Product::category_sum|u16|Функция для нахождения суммы из массива продуктов по категории
print_info()|None|Метод для вывода информации о продукте

**Код программы:**
```Rust
fn main()
{
	let c015 = Product::init("Carrot".to_string(), 1200, Category::Vegetables);
	let c016 = Product::init("Cabbage".to_string(), 3020, Category::Vegetables);
	let b026 = Product::init("Apple".to_string(), 610, Category::Fruits);
	let b028 = Product::init("Banana".to_string(), 900, Category::Fruits);
	let e101 = Product::init("Milk".to_string(), 4500, Category::Dairy);
	let r172 = Product::init("Butter".to_string(), 8750, Category::Dairy);

	let products = [c015, c016, b026, b028, e101, r172];

	let vegetables_sum = Product::category_sum(Category::Vegetables, &products);
	let fruits_sum = Product::category_sum(Category::Fruits, &products);
	let dairy_sum = Product::category_sum(Category::Dairy, &products);

	println!("Vegetables sum: {vegetables_sum}");
	println!("Fruits sum: {fruits_sum}");
	println!("Dairy sum: {dairy_sum}");

	for product in products
	{ product.print_info(); }
}


#[derive(Debug, PartialEq, Eq)]		// Чтобы можно было сравнивать их с помощью "=="
enum Category
{
	Vegetables,
	Fruits,
	Dairy
}


struct Product
{
	name: String,
	price: u16,
	category: Category
}


impl Product
{
	fn init(name: String, price: u16, category: Category) -> Self
	{ Self { name: name, price: price, category: category } }

	fn category_sum(category: Category, products: &[Self]) -> u16
	{
		let mut result = 0;

		for product in products
		{ if product.category == category { result += product.price; } }

		return result;
	}

	fn print_info(&self)
	{
		println!("\nInfo about {:?}:", &self.name);
		match &self.category
		{
			Category::Vegetables => println!("Category: Vegetables"),
			Category::Fruits => println!("Category: Fruits"),
			Category::Dairy => println!("Category: Dairy")
		};
		println!("Price: {:?}", &self.price);
	}
}
```
**Результат:**
```
Vegetables sum: 4220
Fruits sum: 1510
Dairy sum: 13250

Info about "Carrot":
Category: Vegetables
Price: 1200

Info about "Cabbage":
Category: Vegetables
Price: 3020

Info about "Apple":
Category: Fruits
Price: 610

Info about "Banana":
Category: Fruits
Price: 900

Info about "Milk":
Category: Dairy
Price: 4500

Info about "Butter":
Category: Dairy
Price: 8750
```
___
## Задание 8
**Постановка задачи:**
Создайте структуру Employee с полями name, position, salary, а также перечисление Position для должностей сотрудников. Напишите функцию, которая принимает вектор сотрудников и возвращает вектор сотрудников заданной должности.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
Product::init|Self|Функция для инициализации объекта структуры
pos_vector()|Vec<&Employee>|Функция для составления вектора сотрудников заданной должности
print_name()|None|Метод для вывода имени работника

**Код программы:**
```Rust
fn main()
{
	let emp01 = Employee::init("Genady".to_string(), Position::Junior, 68_500);
	let emp02 = Employee::init("Vitaly".to_string(), Position::Middle, 95_000);
	let emp03 = Employee::init("Sergey".to_string(), Position::Senior, 145_000);
	let emp04 = Employee::init("Andrew".to_string(), Position::Senior, 132_800);

	let emp_vector = vec![emp01, emp02, emp03, emp04];

	for employee in &emp_vector
	{ employee.print_name(); }

	let result_vector = pos_vector(&emp_vector, Position::Senior);

	println!("\nAfter pos_vector():\n");
	for employee in &result_vector
	{ employee.print_name(); }
}


#[derive(Debug, PartialEq, Eq)]		// Чтобы можно было сравнивать их с помощью "=="
enum Position
{
	Junior,
	Middle,
	Senior
}


struct Employee
{
	name: String,
	position: Position,
	salary: u32
}


impl Employee
{
	fn init(name: String, position: Position, salary: u32) -> Self
	{ Employee { name: name, position: position, salary: salary } }

	fn print_name(&self)
	{ println!("Name: {:?}", &self.name); }
}


fn pos_vector(employees: &Vec<Employee>, position: Position) -> Vec<&Employee>
{
	let mut result: Vec<&Employee> = Vec::new();

	for employee in employees
	{ if employee.position == position { result.push(employee); } }

	return result;
}
```
**Результат (для Senior):**
```
Name: "Genady"
Name: "Vitaly"
Name: "Sergey"
Name: "Andrew"

After pos_vector():

Name: "Sergey"
Name: "Andrew"
```
___
#### Выполнил студент первого курса группы 1об_ИВТ-2 Пименов Егор