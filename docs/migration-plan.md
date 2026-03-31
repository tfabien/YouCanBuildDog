# Plan de migration

## Stratégie recommandée

Ne pas réécrire la cinématique au début.  
Le plus sûr consiste à **conserver la logique métier** du sketch d'origine et à remplacer progressivement l'IHM et la plateforme.

## Étape 1 — Porter le contrôle servo

- remplacer la lib Arduino Uno par une lib ESP32 compatible servo
- garder le pilotage en microsecondes si le sketch d'origine fonctionne déjà ainsi
- valider les 4 servos un par un

## Étape 2 — Conserver la machine d'état

Reprendre à l'identique :
- `walkAction`
- `walkCount`
- `inMotionFlag`
- séquence de playback
- timings existants

## Étape 3 — Remplacer les boutons

Ancien système :
- 4 boutons pour choisir l'action
- 1 bouton play / programmation
- 1 bouton reset

Nouveau système :
- boutons tactiles à l'écran

## Étape 4 — Ajouter le stockage

Sur ESP32, ajouter ensuite :
- sauvegarde de la séquence
- sauvegarde des offsets

## Architecture logicielle minimale

- `servo_controller.*`
- `motion_engine.*`
- `ui_screens.*`
- `storage.*`

## Bibliothèques typiques

- `ESP32Servo` pour le pilotage servo sur ESP32
- `TFT_eSPI` ou pile déjà utilisée par ta carte
- `XPT2046_Touchscreen` ou équivalent selon la carte
- `Preferences` pour un stockage simple

## Points de vigilance

- ne pas bloquer trop longtemps dans l'UI si les servos doivent rester fluides
- éviter d'alimenter les servos depuis l'ESP32
- valider très tôt les GPIO réellement disponibles sur la carte achetée
