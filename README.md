# Konzolos RPG játék

A program szimulálja 2 paraméterként kapott karakter párbaját.

## Program használata

A program bemenetként vár 2 `json` fájlt.

Példa bemenetre: `.\main.exe .\units\unit1.json .\units\unit2.json`

Példa kimenetre:

`Mapple died. Kakarott wins.`

## Karakter fájl

```json
{
  "name" : "Kakarott",
  "hp" : 3000000,
  "dmg" : 100,
  "attackcooldown" : 2.8
}
```
