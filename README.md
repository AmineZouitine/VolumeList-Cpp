# 🗄 VolumeList-Cpp 🗄 -- WORK IN PROGRESS 👨‍💻


This project allows to add a notion of **volume** in contiguous containers in memory. 
An interesting example of use would be a timetable application.

## Usage

### Useful methods
```cc
VolumeList(size_t max_volume, bool is_dynamic_size = false); // Constructor
void append(T& element, size_t volume);
void insert(T& element, size_t min_position, size_t volume);
void remove(size_t index);
```

### Creation

Creation of a **VolumeList** of type string, with a maximum volume of **100** units and a **non dynamics size**.

```cc
auto volume_list = VolumeList<std::string>{100};  // type can be anything.
```

### Append
The **append** method takes the **element** to be added at the **end** of the list and its **volume**.
Here we add a string with a volume of **10** to our list and a string with a volume of **20**.

**Exemple**
```cc
auto elem1 = std::string("Hi there!");
auto elem2 = std::string("I hope you enjoy it");
volume_list.append(elem1, 10);
volume_list.append(elem2, 20);
```

**List status** *(std::cout << volume_list)*:

```
-------[0]-------
Element: Hi there!
Position: [0, 10]
Volume: 10
-------[1]-------
Element: I hope you enjoy it
Position: [10, 30]
Volume: 20
```

### Insert
The **insert** method takes the **element** to insert, its **volume**, and the place where it **starts** in the volume list.
If there is already an element at this position, it is **shifted**.

**Exemple**
```cc
auto elem1 = std::string("First");
auto elem2 = std::string("Second");
auto elem3 = std::string("Third");
auto elem4 = std::string("Fourth");

volune_list.insert(elem1, 0, 50);
volume_list.insert(elem2, 2, 7);
volume_list.insert(elem3, 2, 9);
volune_list.insert(elem4, 0, 5);
```

**List status** *(std::cout << volume_list)*:
```
-------[0]-------
Element: Fourth
Position: [0, 5]
Volume: 5
-------[1]-------
Element: Third
Position: [5, 14]
Volume: 9
-------[2]-------
Element: Second
Position: [14, 21]
Volume: 7
-------[3]-------
Element: First
Position: [21, 71]
Volume: 50
```

### Remove
The **remove** function allows to remove an element from the list with its **index**, **it works like a classic remove**.

***Exemple***
```cc
auto elem1 = std::string("Bye you :c");
auto elem2 = std::string("Hi there !");
    
volume_list.append(elem1, 10);
volune_list.append(elem2, 20);
volume_list.remove(0);
```

**List status** *(std::cout << volume_list)*:
```
-------[0]-------
Element: Hi there !
Position: [10, 30]
Volume: 20
```
