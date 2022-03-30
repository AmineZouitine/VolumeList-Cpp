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

Creation of a **VolumeList** of type string, with a maximum volume of <span style="color:orange;">Word up</span>**100**</span>` units and a **non dynamics size**.

```cc
auto volume_list = VolumeList<std::string>{100};  // type can be anything.
```

### Append
The append method takes the element to be added at the end of the list and its volume.
Here we add a string with a volume of 10 to our list and a string with a volume of 20.
```cc
auto elem1 = std::string("Hi there!");
auto elem2 = std::string("I hope you enjoy it");
volume_list.append(elem1, 10);
volume_list.append(elem2, 20);
```

List status (std::cout << volume_list):

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
