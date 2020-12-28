# Konzolos RPG játék

A programnak bemeneti paraméterként meg kell adni kettő karaktert majd ők addig fognak egymással harcolni amig az egyikük meg nem hal.

Példa bemenetre: `.\main.exe Maple 150 10 Sally 45 30`

Példa kimenetre:

```
Maple: HP: 150, DMG: 10
Sally: HP: 45, DMG: 30
Maple -> Sally
Maple: HP: 150, DMG: 10
Sally: HP: 35, DMG: 30
Sally -> Maple
Maple: HP: 120, DMG: 10
Sally: HP: 35, DMG: 30
Maple -> Sally
Maple: HP: 120, DMG: 10
Sally: HP: 25, DMG: 30
Sally -> Maple
Maple: HP: 90, DMG: 10
Sally: HP: 25, DMG: 30
Maple -> Sally
Maple: HP: 90, DMG: 10
Sally: HP: 15, DMG: 30
Sally -> Maple
Maple: HP: 60, DMG: 10
Sally: HP: 15, DMG: 30
Maple -> Sally
Maple: HP: 60, DMG: 10
Sally: HP: 5, DMG: 30
Sally -> Maple
Maple: HP: 30, DMG: 10
Sally: HP: 5, DMG: 30
Maple -> Sally
Maple: HP: 30, DMG: 10
Sally: HP: 0, DMG: 30
Sally died. Maple wins.
```
