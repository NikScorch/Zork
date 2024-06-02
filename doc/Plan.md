# Plan

## General Idea

- Dungeon crawler-esc game
- Requires commands to interface with the world
    - Keybinds also available

## Game/Story idea

## Game kernel

- Has a dictionary of `FLAGS` set by the game
    - Flags can be `True` or `False`
    - If a flag is not present, return `False`

## File Format
- Many JSON/YAML files
- Different files for items, rooms, etc.

### Item file format

- Each item has an ID
- Each item can have many descriptions
    - A description can be toggled on or off depending on flags

```json
{
    "id": "bread",
    "description": [
        {
            "requires": "none",
            "text": "Sour dour bread"
        },
        {
            "requires": "readDiary",
            "text": "Made by baker John"
        }
    ],
    "requires": "none",
}
```

### Room file format

- Rooms should be able to have variable shapes
    - In a simple form, this includes the width and height of a cuboid
    - For more complex rooms, this is chaining polygons to create a custom 2d surface
    - L shape rooms should be easy to create, 
    - rooms with triangles and circles? should also be an option *maybe*

```json
{
    "id": "bakery",
    "description": [
        {
            "requires": "none",
            "text": "An old bakery, some freshly laid bread lays on the table"
        },
        {
            "requires": 
        }
    ],
    "shape": {
        
    }
    "doors": [
        {
            
        }
    ]
}
```

### Door file format

```
{

}
```
