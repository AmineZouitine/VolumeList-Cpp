# 🗄 VolumeList-Cpp 🗄 -- WORK IN PROGRESS 👨‍💻


This project allows to add a notion of volume in contiguous containers in memory. 
An interesting example of use would be a timetable application.

##Usage

###Useful methods
```cc
VolumeList(size_t max_volume, bool is_dynamic_size = false); // Constructor
void append(T& element, size_t volume);
void insert(T& element, size_t min_position, size_t volume);
void remove(size_t index);
```

###Creation

Creation of a VolumeList of type string, with a maximum volume of 100 units and a not dynamics size.

```cc
auto volume_list = VolumeList<std::string>{100};  // type can be anything.
```

###Append
The append method takes the element to be added at the end of the list and its volume.
Here we add a string with a volume of 10 to our list and a string with a volume of 20.
```cc
auto elem = std::string("Hi there!");
volume_list.append(elem, 10);
volume_list.append(elem, 20);
```

List status (std::cout << volume_list):

```
-------[0]-------
Element: Boring guy
Position: [0, 10]
Volume: 10
-------[1]-------
Element: Boring guy
Position: [10, 30]
Volume: 20
```

###Insert
