# 💶 Graphical Financial Calculator in C++
> [!NOTE]
> English version is down below.

# 🇩🇪 German Version
Dieses Projekt ist Teil meines Studiums und die Studienleistung für das Modul `Programmieren in C++`. Ich habe mich dazu entschieden einen grafischen Finanzrechner zu programmieren.
Dieser kann Pendlerpauschale, Zinsen, Rendite in Prozent und andere Prozentrechnungen berechnen. 
## 🚗 Pendlerpauschale
Arbeitnehmer in Deutschland können ihre Fahrtkosten von der Steuer absetzen und somit bereits gezahlte Lohnsteuern am Ende eines Steuerjahres zurückbekommen.<br/>
Dies geschieht über die sogenannte Pendlerpauschale, früher Kilometerpauschale genannt, welche eine Pauschale pro gefahrenen Kilometer festlegt.
Momentan liegt diese Pauschale bei **30ct** pro Kilometer bis **20** Kilometer Arbeitsweg. Ab dem **21.** Kilometer Arbeitsweg wird eine Pauschale von **38ct** berechnet.<br/>
Jedoch wird diese Pauschale nur für den kürzesten Anfahrtweg berechnet. Dabei ist egal, ob der Arbeitnehmer diesen Weg als täglichen Arbeitsweg verwendet.
### Wie wird die Pendlerpauschale vom Programm berechnet?
Bis zum einschließlich 20. Kilometer wird die folgende Formel zu Berechnung verwendet:
```
Pendlerpauschale = 0,30 * Anzahl an Arbeitstagen * Kilometer für kürzesten Anfahrtweg
```
Ab dem 21. Kilometer wird diese Formel verwendet:
```
Pendlerpauschale = 0,38 * Anzahl an Arbeitstagen * (Kilometer für kürzesten Anfahrtweg - 20)
```
Wenn der Anfahrtsweg nun über 20 Kilometer lang ist werden beide Formeln verwendet, um den letztendlichen Betrag der Pendlerpauschale zu berechnen.
Beide Ergebnisse werden miteinander addiert und der Gesamtbetrag der Pendlerpauschale entsteht.

## 📈 Zinsrechner

## 💰 Renditerechner

## ％ Prozentrechner

# 🇬🇧 English Version

# 🎨 Style Guide
I used my own code styling, which is similar to code styling used in TypeScript. 
If you're not familiar with the TypeScript code style, don't worry. The following table displays all code styling used in this project.
|Category|Style|Example|
|--|--|--|
|Constants|Upper Snake Case|`THIS_IS_A_CONSTANT`|
|Variables|Camel Case|`startValue`|
|Methods|Camel Case|`performTask()`|
|Classes|Pascal Case|`CommuterBenefit`|

