# YouCanBuildDog ESP32 Touch

Fork-ready bundle to migrate **XRobots/YouCanBuildDog** from Arduino Uno + buttons to **ESP32 tactile + servos branchés directement sur des GPIO PWM**.

## Objectif

Conserver la logique simple du projet d'origine (programmation locale d'une petite séquence de mouvements), tout en remplaçant :

- l'Arduino Uno
- les boutons physiques
- les LEDs d'état

par :

- une carte **ESP32-2432S028** (écran tactile 2.8")
- une interface tactile locale
- un stockage persistant des offsets et de la séquence

## Ce bundle contient

- `docs/hardware.md` : choix matériel et branchements
- `docs/ui.md` : écrans proposés et logique d'usage
- `docs/migration-plan.md` : plan de portage depuis le sketch d'origine
- `docs/assets/` : schémas de branchement + maquettes d'interface

## Limites de ce bundle

Je ne peux pas créer un vrai fork GitHub à ta place depuis ici, ni pousser des commits sur un dépôt distant.
En revanche, ce dossier est prêt à être utilisé comme base de fork local :
1. tu crées ton fork GitHub du repo d'origine,
2. tu ajoutes ce dossier de documentation,
3. tu portes ensuite le code progressivement.

## Carte recommandée

- **ESP32-2432S028** ("Cheap Yellow Display")
- écran 2.8" tactile
- très bon marché
- adaptée à une UI locale simple

## Contraintes importantes

- **Servos alimentés par une alimentation 5V externe**
- **Masse commune obligatoire** entre alimentation servos et ESP32
- **Ne pas alimenter les servos depuis la carte ESP32**

## Proposition de GPIO

Cette proposition vise la simplicité. Elle devra être validée sur la carte exacte achetée, car certaines variantes réservent des GPIO différents pour l'écran/tactile.

- Servo 1: GPIO25
- Servo 2: GPIO27
- Servo 3: GPIO32
- Servo 4: GPIO33

## Références utiles

- Dépôt d'origine : XRobots/YouCanBuildDog
- Exemple de carte ESP32-2432S028 et disposition générale des broches. citeturn912039image1turn912039image8
- Bonnes pratiques d'alimentation de servos avec ESP32 : alimentation externe et masse commune. citeturn912039image2turn912039image4
