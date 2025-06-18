  
# Rust - Лабораторная работа № 2
## Задание 1
**Постановка задачи:**
Создайте структуру Pair, которая хранит два значения одного типа T. Реализуйте методы для получения и изменения значений пары. Убедитесь, что использование ссылок и копирование данных работает корректно.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
get_x()|&T|Функция для получения значения "x" объекта структуры Pair<T\>
get_y()|&T|Функция для получения значения "y" объекта структуры Pair<T\>
set_x()|None|Функция для изменения значения "x" объекта структуры Pair<T\>
set_y()|None|Функция для изменения значения "y" объекта структуры Pair<T\>

**Код программы:**
```Rust
fn main()
{
	let mut some_pair = Pair { x: 13, y: 21};
	let mut x_pair = some_pair.get_x();
	let mut y_pair = some_pair.get_y();

	println!("x = {x_pair}, y = {y_pair}");

	some_pair.set_x(132);
	some_pair.set_y(11);

	x_pair = some_pair.get_x();
	y_pair = some_pair.get_y();

	println!("\nAfter set() methods:");
	print!("x = {x_pair}, y = {y_pair}");
}


struct Pair<T>
{
	x: T,
	y: T
}


impl<T> Pair<T>
{
	fn get_x(&self) -> &T
	{ &self.x }

	fn get_y(&self) -> &T
	{ &self.y }

	fn set_x(&mut self, new_x: T)
	{ self.x = new_x; }

	fn set_y(&mut self, new_y: T)
	{ self.y = new_y; }
}
```
**Результат:**
```
x = 13, y = 21

After set() methods:
x = 132, y = 11
```
___
## Задание 2
**Постановка задачи:**
Определите трейт PrintInfo, который содержит метод print_info(&self). Реализуйте этот трейт для структуры Person, чтобы можно было вызвать метод print_info на объекте Person.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
print_info()|None|Метод трейта PrintInfo, выводящий информацию об объекте структуры Person
**Код программы:**
```Rust
fn main()
{
	let some_person = Person { name: "Shrek".to_string(), age: 51 };
	some_person.print_info();
}


struct Person
{ name: String, age: u8 }


trait PrintInfo
{ fn print_info(&self); }


impl PrintInfo for Person
{
	fn print_info(&self)
	{ println!("Person name: {:?}\nperson age: {:?}", self.name, self.age); }
}
```
**Результат:**
```
Person name: "Shrek"
person age: 51
```
___
## Задание 3
**Постановка задачи:**
Разработайте программу для обработки списка задач (Todo List). Создайте структуру Task с полями id, title и completed, а также методы для добавления, удаления и изменения статуса задачи. Реализуйте вывод информации о всех задачах.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
print_info()|None|Метод, выводящий информацию об объекте структуры Task
delete_status()|None|Метод для удаления статуса задачи
change_status()|None|Метод для изменения статуса задачи

**Код программы:**
```Rust
fn main()
{
	let mut t001 = Task { id: 1, title: "Homework".to_string(), completed: 0};
	let mut t003 = Task { id: 3, title: "Work".to_string(), completed: -1};
	let mut t011 = Task { id: 11, title: "School".to_string(), completed: 1};
	let mut t108 = Task { id: 108, title: "Cooking".to_string(), completed: 0};

	t001.print_info();
	t003.print_info();
	t011.print_info();
	t108.print_info();

	t001.delete_status();
	t003.change_status(1);
	t011.change_status(0);
	t108.change_status(1);

	let todo_list = [t001, t003, t011, t108];

	println!("\nAfter changes:");
	for task in todo_list
	{ task.print_info(); }
}


struct Task 
{
	id: u8,
	title: String,
	completed: i8
}


impl Task
{
	fn print_info(&self)
	{	
		match self.completed
		{
			0 => println!("ID: {:?}; Title: {:?}; Status: Finished", self.id, self.title),
			1 => println!("ID: {:?}; Title: {:?}; Status: Unfinished", self.id, self.title),
			_ => println!("ID: {:?}; Title: {:?}; Status: Unknown", self.id, self.title)
		};
	}

	fn delete_status(&mut self)
	{ self.completed = -1; }

	fn change_status(&mut self, new_status: i8)
	{ self.completed = new_status; }
}
```
**Результат:**
```
ID: 1; Title: "Homework"; Status: Finished
ID: 3; Title: "Work"; Status: Unknown
ID: 11; Title: "School"; Status: Unfinished
ID: 108; Title: "Cooking"; Status: Finished

After changes:
ID: 1; Title: "Homework"; Status: Unknown
ID: 3; Title: "Work"; Status: Unfinished
ID: 11; Title: "School"; Status: Finished
ID: 108; Title: "Cooking"; Status: Unfinished
```
___
## Задание 4
**Постановка задачи:**
Напишите функцию find_unique_elements, которая принимает вектор элементов типа T и возвращает вектор уникальных элементов. Определите трейт Unique c методом is_unique, который проверяет, является ли элемент уникальным.

**Код программы:**
```Rust
fn main()
{
	let some_vector = vec![12, 412, -23, 11, 12, 12, 16, 19, -23];
	let unique_vector = find_unique_elements(some_vector);

	for element in &unique_vector
	{ print!("{element}\t"); }
}


trait Unique<T>
{ fn is_unique(&self, elem: &T) -> bool; }


impl<T: std::cmp::PartialEq> Unique<T> for Vec<T>	// Чтобы можно было сравнивать типы данных "T"
{
	fn is_unique(&self, elem: &T) -> bool
	{
		let mut count: u16;
		count = 0;

		for element in self
		{ if element == elem { count += 1; } }

		if count == 1 { return true; }
		else { return false; }
	}
}


fn find_unique_elements<T: std::cmp::PartialEq + Clone>(vector: Vec<T>) -> Vec<T>
{
	let mut result_vector: Vec<T> = Vec::new();

	for element in &vector
	{ if vector.is_unique(&element) { result_vector.push(element.clone()); } }

	return result_vector;
}
```
**Результат:**
```
412     11      16      19
```
___
## Задание 5
**Постановка задачи:**
Напишите функцию sum_collection, которая принимает коллекцию элементов типа T и возвращает их сумму. Ограничьте тип T требованием наличия метода addition() в некотором трейте Addable для поддержки суммирования. Просуммируйте затем любую коллекцию структур вида:
struct Number { value: u32, }

**Код программы:**
```Rust
fn main()
{
    let n01 = Number { value: 12 };
    let n02 = Number { value: 100 };
    let n03 = Number { value: 3 };
    let n04 = Number { value: 15 };

    let numbers = [n01, n02, n03, n04];
    let some_sum = sum_collection(&numbers);

    println!("Sum = {:?}", some_sum.unwrap().value);
}

trait Addable
{ fn addition(&self, other: &Self) -> Self; }


#[derive(Clone, Debug)]
struct Number
{ value: u32 }


impl Addable for Number
{
    fn addition(&self, other: &Self) -> Self
    { Number { value: self.value + other.value } }
}


fn sum_collection<T: Addable + Clone>(numbers: &[T]) -> Option<T>
{
    let mut sum = numbers[0].clone();

    for number in &numbers[1..]
    { sum = sum.addition(number); }
    
    return Some(sum);
}

```
**Результат:**
```
Sum = 130
```
___
## Задание 6
**Постановка задачи:**
Создайте обобщенную структуру Collection, которая содержит вектор элементов типа T. Реализуйте методы add_element(), get_element() и remove_element(), ограничив тип T trait’ом Clone.

**Список идентификаторов:**
Имя переменной|Тип данных|Смысл
-|-|-
init()|Self|Метод для инициализации коллекции
add_element()|None|Метод для добавления элемента в коллекцию
get_element()|Option<T\>|Метод для получения значения элемента коллекции по индексу 
remove_element()|Option<T\>|Метод для удаления и возвращения элемента коллекции по индексу

**Код программы:**
```Rust
fn main()
{
    let mut some_collection = Collection::init();

    some_collection.add_element(100);
    some_collection.add_element(110);
    some_collection.add_element(111);

    println!("Collection: {:?}", some_collection);

    if let Some(num) = some_collection.get_element(2)
    { println!("Element at index 2: {}", num); }

    if let Some(removed_num) = some_collection.remove_element(0)
    { println!("Removed element: {}", removed_num); }

    println!("After changes: {:?}", some_collection);
}


#[derive(Debug)]
struct Collection<T: Clone>
{ elements: Vec<T> }


impl<T: Clone> Collection<T>
{
    fn init() -> Self
    { Collection { elements: Vec::new() } }

    fn add_element(&mut self, element: T)
    { self.elements.push(element); }

    fn get_element(&self, index: usize) -> Option<T>
    { self.elements.get(index).cloned() }

    fn remove_element(&mut self, index: usize) -> Option<T>
    { Some(self.elements.remove(index)) }
}
```
**Результат:**
```
Collection: Collection { elements: [100, 110, 111] }
Element at index 2: 111
Removed element: 100
After changes: Collection { elements: [110, 111] }
```
___
## Задание 7
**Постановка задачи:**
Создайте трейт Summable, который требует реализации метода sum(&self) -> u32 для типов, поддерживающих сложение. Реализуйте этот трейт для структуры Pair, которая содержит два поля типа T (сумма чисел в этой паре). Добавьте ограничение на тип T для поддержки сложения.

**Код программы:**
```Rust
use std::ops::Add;


fn main()
{
    let some_pair = Pair { x: 15u32, y: 20u32 };

    println!("Sum of pair: {}", some_pair.sum());
}


trait Summable
{ fn sum(&self) -> u32; }


struct Pair<T>
{ x: T, y: T }


impl<T> Summable for Pair<T> where T: Add<Output = u32> + Clone + Copy
{
    fn sum(&self) -> u32
    { self.x + self.y }
}
```
**Результат:**
```
Sum of pair: 35
```
___
#### Выполнил студент первого курса группы 1об_ИВТ-2 Пименов Егор