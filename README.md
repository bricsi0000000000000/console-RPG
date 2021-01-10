# Konzolos RPG játék

Ebben a játékban egy karaktert irányíthatsz és barangolhatsz egy tetszóleges pályán.

A játék során találkozhatsz ellenfelekkel, amikkel meg tudsz küzdeni.

## Játék használata

A program bemenetként vár 3 fájlt:

1. map file
2. player file
3. enemy file

Példa bemenetre: `./a.out maps/map.csv units/unit1.json units/unit2.json`

## Játék menete

4 irányba tudsz lépni.

- jobbra `d`
- balra `a`
- fel `w`
- le `s`

Amikor egy olyan mezőre lépsz, ahol egy ellenfél található *(`M`)*, akkor a van lehetőséged párbajozni vele.

Ilyenkor a párbaj élet halálra megy.

A játék akkor tér véget ha meghalsz.

A játékból kilépni az `e` betű beírásával lehet.

### Jelmagyarázat

| Jel | Magyarázat  |
| --- | ----------- |
| +   | pálya széle |
| -   | pálya széle |
| \|  | pálya széle |
|     | üres cella  |
| #   | fal         |
| o   | játékos     |
| M   | ellenfél    |

## Fejlesztői rész

### Példa egy karakter fájlra

```json
{
  "name" : "Kakarott",
  "hp" : 3000,
  "dmg" : 99,
  "attackcooldown" : 2.8,
  "position_row" : 2,
  "position_column" : 3,
  "number":2
}
```

### Példa egy térkép fájlra

```csv
map_1
0;0;0;0;0;0;0;0;0;0;0;0;0
0;0;1;1;1;1;0;0;0;0;0;1;0
0;0;1;2;0;0;0;0;0;0;0;1
0;0;0;0;0;1;1;1;1;1;0
0;0;0;0;0;0;0;0;3;1;0
0;0;0;0;1;1;1;1;1;1;0
```

| Szám | Magyarázat | Lehet -e ide lépni |
| ---- | ---------- | ------------------ |
| 0    | Üres cella | igen               |
| 1    | Fal        | nem                |
| 2    | Player     | nem                |
| 3    | Enemy      | igen               |

### Példa egy játékra

Itt a játékos a kezdő pozíciójából elment az egyetlen egy ellenfélhez, megtámadta majd megölte. Utána kilépett a játékból.

```


        Stats
                Name: Kakarott
                Health: 3000
                Attack damage: 99
                Attack cooldown: 2.8
                Level: 1
                Current xp: 0
                Necessary xp to next level: 100

+------------+
| ####     # |
| #o       #|
|    ##### |
|       M# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:

        Stats
                Name: Kakarott
                Health: 3000
                Attack damage: 99
                Attack cooldown: 2.8
                Level: 1
                Current xp: 0
                Necessary xp to next level: 100

+------------+
| ####     # |
| #        #|
|  o ##### |
|       M# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:

        Stats
                Name: Kakarott
                Health: 3000
                Attack damage: 99
                Attack cooldown: 2.8
                Level: 1
                Current xp: 0
                Necessary xp to next level: 100

+------------+
| ####     # |
| #        #|
|    ##### |
|  o    M# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:

        Stats
                Name: Kakarott
                Health: 3000
                Attack damage: 99
                Attack cooldown: 2.8
                Level: 1
                Current xp: 0
                Necessary xp to next level: 100

+------------+
| ####     # |
| #        #|
|    ##### |
|   o   M# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:

        Stats
                Name: Kakarott
                Health: 3000
                Attack damage: 99
                Attack cooldown: 2.8
                Level: 1
                Current xp: 0
                Necessary xp to next level: 100

+------------+
| ####     # |
| #        #|
|    ##### |
|    o  M# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:

        Stats
                Name: Kakarott
                Health: 3000
                Attack damage: 99
                Attack cooldown: 2.8
                Level: 1
                Current xp: 0
                Necessary xp to next level: 100

+------------+
| ####     # |
| #        #|
|    ##### |
|     o M# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:

        Stats
                Name: Kakarott
                Health: 3000
                Attack damage: 99
                Attack cooldown: 2.8
                Level: 1
                Current xp: 0
                Necessary xp to next level: 100

+------------+
| ####     # |
| #        #|
|    ##### |
|      oM# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:   -------------There is a monster------------
                Name: Mapple
                Health: 1500
                Attack damage: 80
                Attack cooldown: 2.9
        Would you like to attack the monster? (y/n)     You won


        Stats
                Name: Kakarott
                Health: 6991
                Attack damage: 233.437
                Attack cooldown: 2.8
                Level: 10
                Current xp: 1492
                Necessary xp to next level: 154

+------------+
| ####     # |
| #        #|
|    ##### |
|       o# |
|   ###### |
+----------+
Directions: w,a,s,d
Step:
Exiting game..
```

### Docker images amiket használtam

#### Build program workflow

```Dockerfile
FROM ubuntu:20.04

RUN apt update \
 && DEBIAN_FRONTEND=noninteractive apt install -y \
  make \
  cmake \
  cppcheck \
  g++ \
  git \
  valgrind \
&& rm -rf /var/lib/apt/lists/*
```

#### Google unit test workflow

```Dockerfile
FROM ubuntu:20.04

RUN apt update \
 && DEBIAN_FRONTEND=noninteractive apt install -y \
    make \
    cmake \
    git \
    libgtest-dev \
    gcc g++ \
 && cd /usr/src/gtest \
 && cmake CMakeLists.txt \
 && make \
 && ln -st /usr/lib/ /usr/src/gtest/libgtest.a \
 && ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a \
 && rm -rf /var/lib/apt/lists/*
```

#### Doxygen workflow

```Dockerfile
FROM ubuntu:20.04

RUN apt update \
 && DEBIAN_FRONTEND=noninteractive apt install -y \
  doxygen \
  graphviz \
  git \
&& rm -rf /var/lib/apt/lists/*
```
