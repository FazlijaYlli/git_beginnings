# Utiliser facilement `git` (Si, si, c'est possible)

---
## HEIG-VD 25-26 - PRG1
*Rédigé par Ylli Fazlija*


## 🏗️ Table des matières
<!-- TOC -->
* [Utiliser facilement `git` (Si, si, c'est possible)](#utiliser-facilement-git-si-si-cest-possible)
  * [📖 Préface](#-préface)
  * [🤔 `git` ? C'est quoi ?](#-git--cest-quoi-)
    * [💬 Réponse courte](#-réponse-courte)
    * [👴 Création de `git`](#-création-de-git)
    * [🚚 Architecture générale de `git`](#-architecture-générale-de-git)
  * [💾 Installer `git`](#-installer-git)
    * [🪟 Windows](#-windows)
    * [🍎 MacOS](#-macos)
    * [🐧 Linux](#-linux)
    * [🔧 Vérifier que `git` est bien installé](#-vérifier-que-git-est-bien-installé)
  * [🐙 GitHub](#-github)
    * [📣 Se créer un compte](#-se-créer-un-compte)
    * [🎈 Créer un repository de test](#-créer-un-repository-de-test)
    * [🔑 Créer et ajouter des clés de chiffrement/signature à votre compte](#-créer-et-ajouter-des-clés-de-chiffrementsignature-à-votre-compte)
      * [1. Chiffrement ?](#1-chiffrement-)
      * [2. Signature ?](#2-signature-)
      * [3. E-mail et nom d'utilisateur.trice](#3-e-mail-et-nom-dutilisateurtrice)
      * [4. Générer une paire de clés pour votre compte](#4-générer-une-paire-de-clés-pour-votre-compte)
      * [5. Ajouter vos clés de chiffrement et signature à votre compte GitHub.](#5-ajouter-vos-clés-de-chiffrement-et-signature-à-votre-compte-github)
        * [Clé de chiffrement](#clé-de-chiffrement)
        * [Clé de signature](#clé-de-signature)
      * [6. Indiquer l'emplacement de votre clé de signature à git](#6-indiquer-lemplacement-de-votre-clé-de-signature-à-git)
  * [🔨 Premiers pas](#-premiers-pas)
    * [🗝️ Cloner son repository en SSH](#-cloner-son-repository-en-ssh)
    * [🧃 Ajouter des fichiers à un commit](#-ajouter-des-fichiers-à-un-commit)
      * [1. Créer / Modifier des fichiers dans le `repository`](#1-créer--modifier-des-fichiers-dans-le-repository)
      * [2. Comment `stage` les fichiers modifiés](#2-comment-stage-les-fichiers-modifiés)
    * [✉️ Créer un commit et le pousser sur GitHub](#-créer-un-commit-et-le-pousser-sur-github)
      * [1. Création d'un commit](#1-création-dun-commit)
      * [2. Pousser ses modifications](#2-pousser-ses-modifications)
      * [3. Garder son repository à jour](#3-garder-son-repository-à-jour)
  * [🌳 Utiliser des branches](#-utiliser-des-branches)
    * [🌵 Des branches ?](#-des-branches-)
      * [1. Qu'est-ce qu'on branche ?](#1-quest-ce-quon-branche-)
      * [2. Pourquoi créer des branches ?](#2-pourquoi-créer-des-branches-)
    * [🌱 Créer et travailler sur une branche](#-créer-et-travailler-sur-une-branche)
      * [1. Créer une branche](#1-créer-une-branche)
      * [2. Changer de branche](#2-changer-de-branche)
    * [🌹 Fusionner deux branches](#-fusionner-deux-branches)
  * [💥 Gestion des conflits de fusion](#-gestion-des-conflits-de-fusion)
    * [🤼 Un conflit ?](#-un-conflit-)
  * [🔬 Utilisation de `git` pour les laboratoires](#-utilisation-de-git-pour-les-laboratoires)
    * [🧠 Réflexion](#-réflexion)
    * [🪵 Branches](#-branches)
    * [🤝 Rendu](#-rendu)
  * [📄 Feuille de triche pour `git`](#-feuille-de-triche-pour-git)
<!-- TOC -->

---
## 📖 Préface
*Le but de ce court document est de vous donner toutes les bases nécessaires dans le contexte de votre formation 
à la HEIG-VD ainsi que de servir de résumé de la démonstration effectuée en classe le `23.09.2025`. Si vous n'avez pas
pu suivre la démo, veillez à bien effectuer les actions des différentes sections dans l'ordre.*

*`git` est un outil qui vous sera utile pour la grande majorité de vos projets et de ce fait, 
permet des manipulations très complexes. Par conséquent, ce document ne couvre absolument pas
l'étendue des fonctionnalités du programme. Si jamais une partie de ce document n'est pas claire ou
vous avez besoin de plus de détails sur une section en particulier, je vous invite **très** fortement à consulter
le "git Book" [disponible gratuitement à cette addresse](https://git-scm.com/book/en/v2).*

Dans les exemples de commandes, les mots entre chevrons en majuscules indiquent un paramètre à insérer.

---
## 🤔 `git` ? C'est quoi ?
### 💬 Réponse courte
`git` est un programme offrant la possibilité de centraliser un projet sur un serveur et de permettre à plusieurs 
personnes d'éditer les fichiers de celui-ci sur des copies de ce projet appelés `clones` et par la suite, synchroniser 
chaque changement sur les machines de chacun. Ce processus s'appelle VCS, ou *Version Control System*.
### 👴 Création de `git`
L'outil `git` fut créé par Linus Torvalds (inventeur de 🐧 Linux !) avec pour but, à la base, de gérer de manière 
efficace les fichiers du kernel Linux.
### 🚚 Architecture générale de `git`
`git` fonctionne grâce à une architecture client-serveur. Le serveur est appelé `repository` et les clients sont appelé 
`clones`. Le projet présent sur le serveur est la seule source de vérité. Chaque `clone` est une copie locale du projet.

Afin de garder un historique des changements sur le serveur, `git` utilise des `commits`, qui sont, basiquement, 
des sauvegardes d'un état du projet à un moment donné. Chaque développeur.se travaille sur un `clone`.

Lorsque des modifications sont effectuées sur un `clone`, elles sont détectées par `git`. Lorsqu'on sélectionne les
modifications que l'on veut appliquer au projet depuis un clone, leurs statut passe de `unstaged` à `staged`. Vous
pouvez voir le mot-clé `staged` comme "est ajouté au prochain commit".

Finalement, lorsque vous voulez sauvegarder l'état de votre projet dans l'historique des versions git, vous
créerez un `commit`, qui contiendra toutes les modifications notées comme `staged`.

Si cela vous paraît confus pour l'instant, c'est normal. Vous verrez en contexte dans les chapitres suivants 😊

---
## 💾 Installer `git`
### 🪟 Windows
La manière la plus simple d'utiliser `git` sous Windows est de télécharger l'installateur depuis [git-scm](https://git-scm.com/downloads/win).
Dans la liste des fichiers, cliquez sur `Git for Windows/x64 Setup`. Ensuite, exécutez l'installateur, et terminez 
l'installation sans changer de paramètres. 

`git` pourra ensuite être utilisé depuis un terminal comme cmd, Powershell ou
Git Bash (installé avec `git` depuis le même installateur).

<u>**[Git pour Windows](https://git-scm.com/downloads/win)**</u>


### 🍎 MacOS
Sur la page des téléchargements MacOS de [git-scm](https://git-scm.com/downloads/mac), il est recommandé d'utiliser `homebrew` ou `MacPorts` pour 
télécharger et installer le package `git`.

<u>**[Git for MacOS](https://git-scm.com/downloads/mac)**</u>


### 🐧 Linux
`git` est souvent préinstallé sur les machines Linux, mais dans le cas où votre distribution ne comprends pas `git`, 
installez le package `git` depuis votre package manager. Si cela vous intéresse, il est aussi possible de compiler
`git` directement depuis ses fichiers sources. 

<u>**[Git for Linux](https://git-scm.com/downloads/linux)**</u>


### 🔧 Vérifier que `git` est bien installé
Ouvrez le terminal de votre choix et lancez la commande `git --version`. Si la version s'affiche, c'est que
`git` est correctement installé. Bien joué ! Sinon, renvoyez les étapes d'installation ou demandez-moi de l'aide 😊

---
## 🐙 GitHub
Avant de s'attaquer à l'outil `git` en soi, il va falloir préparer GitHub à reçevoir vos données. GitHub offre
la possibilité d'héberger son repository en ligne, permettant de travailler sur le projet possible depuis n'importe où.

### 📣 Se créer un compte
Rendez-vous sur GitHub et suivez les étapes pour vous créer un compte. Utiliser votre adresse e-mail HEIG-VD peut être
pratique si vous souhaitez séparer vos projets académiques de vos projets personnels.

---
### 🎈 Créer un repository de test
Depuis la page d'accueil sur GitHub, cliquez sur le bouton vert "New" pour créer un nouveau repository. Ensuite,
donnez-lui un nom et une description. Ne changez pas les autres options et créez le repository à l'aide du bouton vert
en bas de la page.

---
### 🔑 Créer et ajouter des clés de chiffrement/signature à votre compte
Cette étape est **très importante** ! Veillez à bien suivre les instructions qui suivent.

#### 1. Chiffrement ?
Lorsque que vous allez sauvegarder vos modifications à l'aide de `commits` et les envoyer sur les serveurs de fichiers
GitHub, ces données peuvent être chiffrées à l'aide d'une paire de clés SSH afin de ne pas communiquer en clair.

#### 2. Signature ?
Les commits `git` peuvent utiliser une paire de clé (aussi SSH dans notre cas) pour ajouter
une signature à un commit. Un commit signé prouve qu'il provient bien de vous et non une personne
tierce tenant d'usurper votre identité.

#### 3. E-mail et nom d'utilisateur.trice
Premièrement, ouvrez votre terminal et entrez ces commandes une par une, en insérant les paramètres correspondants. Veillez à bien
renseigner l'adresse e-mail et le nom d'utilisateur que vous avez utilisé pour la création de votre compte GitHub.
```shell
# Configuration des informations que git utilisera dans vos commits.
git config --global user.email <YOUR_EMAIL_ADDRESS>
git config --global user.name <YOUR_USERNAME>
git config --global commit.gpgSign true
git config gpg.format ssh
```
Ces commandes définissent l'email et le nom d'utilisateur à utiliser par défaut. La dernière commande permet
d'activer la signature de commit par défaut et renseigne le type de la clé de signature qui sera utilisé.

#### 4. Générer une paire de clés pour votre compte
Afin de générer une paire de clés, entrez cette commande.
```shell
# Génère une nouvelle paire de clé SSH
ssh-keygen -t ed25519 -C "your_email@example.com"
```
Lorsqu'il vous est demandé de choisir un nom de fichier, appuyez sur entrée pour garder le nom par défaut.
Ensuite, entrez un mot de passe de votre choix quand le programme vous demande une "passphrase". Choissisez un
mot de passe bien sécurisé !

Vos clés sont désormais créées. Elles se trouvent dans votre dossier utilisateur, dans un dossier caché `.ssh` dans
votre dossier utilisateur.

#### 5. Ajouter vos clés de chiffrement et signature à votre compte GitHub
Depuis la page d'accueil de GitHub, rendez-vous dans les paramètres de votre compte.
Dans la liste de gauche, trouvez la catégorie "**SSH and GPG keys**".

##### Clé de chiffrement
Cliquez sur le bouton vert pour ajouter une clé SSH. Donnez-lui un titre et choissisez le type "Authentication key".
Dans la fenêtre "Key", insérez le contenu du fichier `<HOME>/.ssh/id_ed25519.pub`. (Un des deux fichiers générés 
précédemment.)

##### Clé de signature
Créez une clé exactement de la même manière que la clé de chiffrement SSH, avec comme seule différence le 
"Key type" doit être "Signing key".

#### 6. Indiquer l'emplacement de votre clé de signature à git
```shell
# Génère une nouvelle paire de clé SSH
git config --global user.signingkey <PATH_TO_SSHKEY>
```
**IMPORTANT :** Vous devez mentionner le chemin vers la clé **privée** (sans extension ".pub") et non la clé publique (
avec extension ".pub")

---
## 🔨 Premiers pas
Bravo, vous en avez terminé avec les clés de chiffrement et de signature !
Dans cette section, vous apprendrez vos premières commandes pour commencer à expérimenter avec `git` et ses 
fonctionnalités. Commencez ce chapitre en ouvrant un terminal dans le `clone` de votre repository GitHub,
créé juste au dessus.

### 🗝️ Cloner son repository en SSH
Afin de vérifier si votre configuration SSH est correcte, vous allez clonez le respository que
vous avez créé. Depuis la page GitHub de votre repository, vous trouverez un lien structuré comme ceci.
(user_name et repo_name remplacement respectivement votre pseudonyme
et titre de votre `repository`)
```
git@github.com:user_name/repo_name.git
```
Il s'agit du lien qui sera utilisé pour cloner votre projet en utilisant le chiffrement SSH. 

**IMPORTANT** : ne PAS
utiliser l'autre lien commençant par `https://`.

Lancez cette commande en remplaçant `<SSH_URL>` par l'addresse SSH de votre repository mentionnée juste au-dessus :
```shell
git clone <SSH_URL>
```
Si tout se passe bien, `git` vous demandera d'entrer le mot de passe (passphrase) que vous avez choisi lors de la génération de
votre clé de chiffrement. Entrez ce dernier et si tout se passe bien, `git` créera un nouveau dossier en local sur votre machine.
C'est un `clone` de votre premier projet ! Si ça se passe mal (permission denied), revoyez votre configuration SSH.

<sub>Pour plus de détails : https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository</sub>

### 🧃 Ajouter des fichiers à un commit

#### 1. Créer / Modifier des fichiers dans le `repository`
Créer ou modifier un fichier présent dans le dossier du projet fera réagir `git` et nous permettra d'ajouter ces
modifications à un commit.

Un fichier essentiel à un bon projet est un `README.md`. Créez ce dernier et entrez quelques informations dedans,
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

### ✉️ Créer un commit et le pousser sur GitHub
#### 1. Création d'un commit
Finalement, on peut créer un commit en exécutant cette commande :
```shell
# Le paramètre -m permets d'ajouter un titre au commit.
git commit -m "Mon premier commit"
```
Ce commit contiendra toutes les informations marquées comme "staged".
Il est possible de vérifier l'état du `repository` en relançant `git status`, qui devrait
vous renvoyer un message comme celui-ci :

```
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
#### 2. Pousser ses modifications
Nos modifications sont prêtes à être envoyées sur le repository GitHub. Pour cela, une seule et
simple commande suffit :
```shell
git push
```
Vous devrez entrer une nouvelle fois le mot de passe de votre clé SSH. Une fois ceci fait,
le contenu de votre commit devrait être disponible depuis la page GitHub ! 

Pour le vérifier, allez sur la page de votre repository GitHub et vérifiez si le commit est bien présent.

**IMPORTANT** : Dans la liste des commits du repository, votre commit doit bien apparaître comme "Verified".

Bravo, vous avez créé et poussé votre premier commit signé et chiffré ! C'est de cette manière
que vous synchroniserez vos changements sur vos projets de laboratoires.

#### 3. Garder son repository à jour
Si un de vos collègues a poussé ses modifications sur le repository, il faut manuellement demander à `git` de
mettre à jour votre clone actuel avec cette commande :

```shell
# git ira chercher les dernières modifications du repo et les téléchargera
git pull
```
 
En plus d'aller chercher les dernières modifications, cette commande va directement les fusionner
avec votre clone local actuel si aucun conflit n'est détecté.

Si des conflits sont détectés, ce document les traite dans le chapitre suivant.

<sub>Pour plus de détails : https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository</sub>

## 🌳 Utiliser des branches
### 🌵 Des branches ?
#### 1. Qu'est-ce qu'on branche ?
`git` fonctionne avec un système de branches. Dans votre repository de test, vous serez 
sur la branche "main". Chaque commit que vous effectuerez seront liés à cette branche.
#### 2. Pourquoi créer des branches ?
Le but des branches est de fournir à un ou plusieurs collaborateurs un espace pour travailler
sur une fonction ou partie spécifique du projet et ne pas avoir à gérer les modifications
que d'autres collaborateurs poussent sur d'autres parties du projet.

Par exemple, en partant de la branche principale `main`, on créera une branche `bug_fix`.
En créant des commits sur cette branche et non sur la branche principale, on garantit que
le contenu présent sur main n'est pas touché avant d'être sûr que le contenu modifié dans la
branche `bug_fix` est prêt. Ensuite, le contenu de la branche `bug_fix` et fusionné à la branche `main`

<sub>Pour plus d'informations sur les branches : https://git-scm.com/book/en/v2/Git-Branching-Branches-in-a-Nutshell</sub>
### 🌱 Créer et travailler sur une branche
#### 1. Créer une branche
Pour créer une branche, exécutez cette commande dans votre terminal :
```shell
# Crée une branche du nom mentionné depuis la branche actuelle
git branch <BRANCH_NAME>
```
Ceci créera une branche à partir de la branche sur laquelle git se trouvait. Le contenu sur
la branche de départ et la branche créée est donc exactement le même tant qu'aucune modification n'est
effectuée.

#### 2. Changer de branche
Après avoir créé une branche, `git` reste sur la branche de départ. Si vous souhaitez travailler sur
une autre branche, utilisez la commande suivante pour changer de branche.
```shell
# Essaie d'aller sur la branche mentionnée en paramètre 
git switch <BRANCH_NAME>
```

### 🌹 Fusionner deux branches
La fusion d'une branche appelée `feature` dans la branche `main` se fait comme ceci :
```shell
# On se déplace sur la branche main
git checkout main

# On merge la branche souhaitée
git merge feature
```

`git` vous demandera peut-être de choisir un mode de fusion. Pour l'instant, choisissez `fast-forward`.

Si aucun conflit n'est détecté, le merge s'effectue et les ajouts de la branche
`feature` sont disponibles sur la branche `main`.

---
## 💥 Gestion des conflits de fusion
### 🤼 Un conflit ?
Les conflits apparaissent lorsque d'une fusion entre deux branches, et que celles-ci contiennent
du contenu différent pour un même endroit dans le projet.

Lorsque cela arrive, il faut les résoudre manuellement. Ce sujet est bien plus compréhensible avec
des exemples, c'est pourquoi je vous invite à lire le chapitre[ "Basic Merge Conflicts" du git Book.](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging)

Ce qu'il faut retenir, c'est que lors d'un conflit, `git`va annoter dans les fichiers concernés les lignes
nécéssitant un choix. Une fois résolus, les commits peuvent être réalisés sans soucis.

---
## 🔬 Utilisation de `git` pour les laboratoires
Notre souhait dans ce cours de PRG1 et de vous former au plus vite à l'utilisation de `git` dans votre
formation à la HEIG-VD. Il s'agit d'un outil que vous retrouverez dans une grande majorité des cours et qui facilite grandement
le travail à plusieurs sur un projet.

Dans ce dernier chapitre, nous vous offrons quelques recommandations pour l'utilisation de `git`
dans le contexte du cours de PRG1.
### 🧠 Réflexion
Il est important lors d'un travail à plusieurs de réfléchir correctement à un partage du travail
équitable et qui peut être décomposé en tâches à réaliser par chacun.

Ces tâches doivent dépendre le moins possible d'une autre tâche, afin de permettre
une certaine indépendance pour chaque membre de l'équipe, et de ne pas avoir à faire
attendre un membre de l'équipe sur un autre.
### 🪵 Branches
Un bon réflexe à vite adopter avec des projets `git` : ***"Branch early and branch often"***
Ce qui signfie qu'il vaut mieux créer de multiples petites branches dans le projet et les
merger dans la branche principale souvent. De cette manière, les commits sont catégorisé
sous leur branche respective.

### 🤝 Rendu
Il est fortement souhaitable que le commit du rendu soit marqué comme tel (avec une release,
GitHub de préférence)

## 📄 Feuille de triche pour `git`
Une excellente cheatsheet créée par GitHub est disponible sur [leur site.](https://training.github.com/)
Gardez-la quelque part de facile à lire !
