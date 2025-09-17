# Utiliser facilement `git` (Si, si, c'est possible)

---
## HEIG-VD 25-26 - PRG1
*Rédigé par Ylli Fazlija*

---
## 📖 Préface
*Le but de ce court document est de vous donner toutes les bases nécessaires dans le contexte de votre formation 
à la HEIG-VD ainsi que de servir de résumé de la démonstration effectuée en classe le `23.09.2025`. Si vous n'avez pas
pu suivre la démo, veillez à bien effectuer les actions des différentes sections dans l'ordre.*

*`git` est un outil qui vous sera utile pour la grande majorité de vos projets et de ce fait, 
permet des manipulations très complexes.*

*(Dans les exemples de commandes, les mots entre chevrons en majuscules indiquent un paramètre à insérer.)*

---
## 🤔 `git` ? C'est quoi ?
### Réponse courte 💬
`git` est un programme offrant la possibilité de centraliser un projet sur un serveur et de permettre à plusieurs 
personnes d'éditer les fichiers de celui-ci sur des copies de ce projet appelés `clones` et par la suite, synchroniser 
chaque changement sur les machines de chacun. Ce processus s'appelle VCS, ou *Version Control System*.
### Création de `git` 👴
L'outil `git` fut créé par Linus Torvalds (inventeur de 🐧 Linux !) avec pour but, à la base, de gérer de manière 
efficace les fichiers du kernel Linux.
### Architecture générale de `git` 🚚
`git` fonctionne grâce à une architecture client-serveur. Le serveur est appelé `repository` et les clients sont appelé 
`clones`. Le projet présent sur le serveur est la seule source de vérité. Chaque `clone` est une copie locale du projet.

Afin de garder un historique des changement sur le serveur, `git` utilise des `commits`, qui sont, basiquement, 
des sauvegardes d'un état du projet à un moment donné. Chaque développeur.se travaille sur un `clone`.

Lorsque des modifications sont effectuées sur un `clone`, elles sont détectées par `git`. Lorsqu'on sélectionne les
modifications que l'on veut appliquer au projet depuis un clone, leurs statut passe de `unstaged` à `staged`. Vous
pouvez voir le mot-clé `staged` comme "est ajouté au prochain commit".

Et finalement lorsque vous voulez sauvegarder l'état de votre projet dans l'historique des versions git, vous
créerez un `commit`, qui contiendra toutes les modifications notées comme `staged`.

Si cela vous paraît confus pour l'instant, c'est normal. Vous verrez en contexte dans les chapitres suivants 😊

---
## 💾 Installer `git`
### Windows 🪟
La manière la plus simple d'utiliser git sous Windows est de télécharger l'installateur depuis [git-scm](https://git-scm.com/downloads/win).
Dans la liste des fichiers, cliquez sur `Git for Windows/x64 Setup`. Ensuite, exécutez l'installateur, et terminez 
l'installation sans changer de paramètres. 

`git` pourra ensuite être utilisé depuis un terminal comme cmd, Powershell ou
Git Bash (installé avec git avec le même installateur).

<u>**[Git pour Windows](https://git-scm.com/downloads/win)**</u>

---
### MacOS 🍎
Sur la page des téléchargements MacOS de [git-scm](https://git-scm.com/downloads/mac), il est recommandé d'utiliser `homebrew` ou `MacPorts` pour 
télécharger et installer le package `git`.

<u>**[Git for MacOS](https://git-scm.com/downloads/mac)**</u>

---
### Linux 🐧
git est souvent préinstallé sur les machines Linux, mais dans le cas où votre distribution ne comprends pas git, 
installez le package `git` depuis votre package manager. Si cela vous intéresse, il est aussi possible de compiler
git directement depuis ses fichiers sources. 

<u>**[Git for Linux](https://git-scm.com/downloads/linux)**</u>

---
## 🐙 GitHub
Avant de s'attaquer à l'outil `git` en soi, il va falloir préparer GitHub à reçevoir vos données. GitHub offre
la possibilité d'héberger son repository en ligne, permettant le travail sur le projet possible depuis n'importe ou.

### Se créer un compte 📣
Rendez-vous sur GitHub et suivez les étapes pour vous créer un compte. Utiliser votre adresse e-mail HEIG-VD peut être
pratique si vous souhaitez séparer vos projets écoliers de vos projets personnels.
---
### Créer un repository de test 🎈
Depuis la page d'accueil sur GitHub, cliquez sur le bouton vert "New" pour créer un nouveau repository. Ensuite,
donnez-lui un nom et une description. Ne changez pas les autres options et créez le repository à l'aide du bouton vert
en bas de la page.
---
### Créer et ajouter des clés de chiffrement/signature à votre compte 🔑
Cette étape est **très importante** ! Veillez à bien suivre les instructions qui suivent.

#### 1. Chiffrement ?
Lorsque que vous allez sauvegarder vos modifications à l'aide de `commits` et les envoyer sur les serveur de fichiers
GitHub, ces données peuvent être chiffrées à l'aide d'une paire de clés SSH afin de ne pas communiquer en clair.

#### 2. Signature ?
Les commits git peuvent utiliser une paire de clé (aussi SSH dans notre cas) pour ajouter
une signature à un commit. Un commit signé prouve qu'il provient bien de vous et non une personne
tierce tenant d'usurper votre identité.

#### 3. E-mail et nom d'utilisateur.trice
Premièrement, ouvrez votre terminal et entrez ces commandes, en insérant les paramètres correspondants. Veillez à bien
renseigner l'addresse e-mail et le nom d'utilisateur que vous avez utilisé pour la création de votre compte GitHub.
```shell
# Configuration des informations que git utilisera dans vos commits.
git config --global user.email=<YOUR_EMAIL_ADDRESS>
git config --global user.name=<YOUR_USERNAME>
git config --global commit.gpgSign true
git config gpg.format ssh
```
Ces commandes définissent l'email et le nom d'utilisateur à utiliser par défaut. La dernière commande permets
d'activer la signature de commit par défaut et reseigne le type de la clé de signature qui sera utilisé.

#### 4. Générer une paire de clés pour votre compte
Afin de générer une paire de clés, entrez cette commande.
```shell
# Génère une nouvelle paire de clé SSH
ssh-keygen -t ed25519 -C "your_email@example.com"
```
Lorsqu'il vous est demandé de choisir nom de fichiers, appuyez sur entrée pour garder le nom par défaut.
Ensuite, entrez un mot de passe de votre choix quand le programme vous demande une "passphrase". Choissisez un
mot de passe bien sécurisé !

Vos clés sont désormais créées. Elles se trouvent dans votre dossier utilisateur, dans un dossier caché `.ssh` dans
votre dossier utilisateur.

#### 5. Ajouter vos clés de chiffrement et signature à votre compte GitHub.
Depuis la page d'accueil de GitHub, rendez-vous dans les paramètres de votre compte.
Dans la liste de gauche, trouvez la catégorie "**SSH and GPG keys**".

##### Clé de chiffrement
Cliquez sur le bouton vert pour ajouter une clé SSH. Donnez-lui un titre et choissisez le type "Authenticiation key".
Dans la fenêtre "Key", insérez le contenu du fichier `<HOME>/.ssh/id_ed25519.pub`. (Un des deux fichiers générés 
précédemment.)

##### Clé de signature
Créez une clé exactement de la même manière que la clé de chiffrement SSH, avec comme seule différence le 
"Key type" doit être "Signing key".

#### 6. Indiquer l'emplacement de votre clé de signature à git
```shell
# Génère une nouvelle paire de clé SSH
git config --global user.signingkey=<PATH_TO_SSHKEY>
```
**IMPORTANT :** Vous devez mentionner le chemin vers la clé **privée** (sans extension ".pub") et non la clé publique (
avec extension ".pub")

#### 7. Vérification du fonctionnement de vos clés de chiffrement
Afin de vérifier si votre configuration SSH est correcte, vous allez clonez le respository que
vous avez créé. Depuis la page GitHub de votre repository, vous trouverez un lien structuré comme ceci.
(user_name et repo_name remplacement respectivement votre pseudonyme
et titre de votre `repository`)
```
git@github.com:user_name/repo_name.git
```
Il s'agit du lien qui sera utilisé pour cloner votre git en utilisant le chiffrement SSH. **IMPORTANT** : ne PAS
utiliser l'autre lien commençant par `https://`.

Lancez cette commande en remplaçant `<SSH_URL>` par l'addresse SSH de votre repository mentionnée juste au-dessus :
```shell
git clone <SSH_URL>
```
Si tout se passe bien, `git` vous demandera d'entrer le mot de passe (passphrase) que vous avez choisi lors de la génération de
vos clés SSH. Entrez ce dernier et si tout se passe bien, git créera un nouveau dossier en local sur votre machine.
C'est un `clone` de votre premier projet !

---
## 🔨 Votre premier projet
Bravo, vous en avez terminé avec les clés de chiffrement et de signature !
Dans cette section, vous apprendrez vos premières commandes `git` pour commencer à expérimenter avec git et ses 
fonctionnalités.

### Vérifier que `git` est bien installé 🔧
Ouvrez le terminal de votre choix et lancez la commande `git --version`. Si la version s'affiche, c'est que
`git` est correctement installé. Bien joué ! Sinon, renvoyez les étapes d'installation ou demandez-moi de l'aide 😊
### Initialiser un `repository` avec `git init` 📂
#### 1. Ouvrir un terminal et naviguer dans le dossier du projet
Selon votre système d'exploitation, votre terminal sera différent. Sur MacOS et Linux, le terminal pré-installé
fonctionnera parfaitement tant qu'il a accès à git.
Sur Windows, vous pouvez utiliser Powershell ou Git Bash **(recommandé)**. 

Le terminal s'ouvrira par défaut dans votre dossier "home", portant
votre nom d'utilisateur. Depuis là, vous pouvez utiliser les comamndes suivantes pour vous déplacer dans votre
arboresnce de fichiers.

```shell
# Lister le contenu du dossier actuel
ls

# Naviguer dans le dossier
cd <PATH>

# Créer un dossier
mkdir <DIRNAME>

# Supprimer un dossier
rm -r <DIRNAME>
```
Naviguez jusqu'à ce que votre terminal se trouve dans le dossier souhaité.

#### 2. Initialiser un `repository`
Lorsque vous vous trouvez dans le dossier souhaité, la commande suivante permets d'initialiser git et de créer
un repository dans ce dossier.
```shell
# Initialisation d'un nouveau repository git dans le dossier actuel, en nommant la branche principale "main".
git init --initial-branch=main
```
Un message de succès comme celui-ci s'affichera.
```shell
# Initialisation correcte du repository
Initialized empty Git repository in /Your/Path/Here/.git/
```
Désormais, n'importe quel changement d'état dans les fichiers présents dans ce dossier seront reconnus par `git`.
C'est ce qu'on va tester maintenant ! ⬇️
### Préparer ses fichiers modifiés à être sauvegardés 🧳
#### 1. Créer / Modifier des fichiers dans le `repository
Créer ou modifier un fichier présent dans le dossier du projet fera réagir `git` et nous permettra d'ajouter ces
modifications à un commit.

Un fichier essentiel à un bon projet git est un `README.md`. Créez ce dernier et entrez quelques informations dedans,
comme votre nom et le titre du `repository`.

#### 2. Comment `stage` les fichiers modifiés
Une fois votre fichier modifié, il est possible de vérifier que `git` a bien détecté vos ajouts en
lançant la commande suivante :

```shell
# Informe l'utilisateur des derniers changements.
git status
```
Cette commande devrait vous retourner un message similaire à ceci :
```
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md

nothing added to commit but untracked files present (use "git add" to track)
```
`git` a bien détecté une modification sur `README.md` ! Pour l'instant, le fichier est `untracked` ou `unstaged`. Ceci
signifie qu'il ne sera pas pris en compte dans le prochain `commit`. Comme le message vous l'indique,
la commande pour ajouter ce fichier au prochain commit est la suivante :

```shell
# Ajoute un fichier au commit.
git add <FILENAME>
```
Lancez donc cette commande en entrant `README.md` (ou le nom du fichier que vous avez ajouté/modifié) comme paramètre,
et exécutez `git status` une nouvelle fois. Le retour devrait ressembler à ceci :

```
Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md
```

Finalement, on peut créer un commit 

### Créer un commit
### Lier le repository à GitHub
### Envoyer les commits au serveur
## 🌳 Travailler avec des branches
### Créer une branche
### Fusionner deux branches
## 💥 Gestion des conflits
### Utiliser`merge`
### Utiliser `rebase`
### Utiliser `squash`
## 🔬 Utilisation de `git` pour les laboratoires
### Réflexion
### Branches
### Rendu
## 📄 Cheatsheet