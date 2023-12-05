# TP9_Graphe
## Binome
YAMANI Abdeslam P2207683
RAVELOSON Maherinirina P2003422


## Getting started

To make it easy for you to get started with GitLab, here's a list of recommended next steps.

Already a pro? Just edit this README.md and make it your own. Want to make it easy? [Use the template at the bottom](#editing-this-readme)!

## Add your files

- [ ] [Create](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) or [upload](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) files
- [ ] [Add files using the command line](https://docs.gitlab.com/ee/gitlab-basics/add-file.html#add-a-file-using-the-command-line) or push an existing Git repository with the following command:

```
cd existing_repo
git remote add origin https://forge.univ-lyon1.fr/p2207683/tp9_graphe.git
git branch -M main
git push -uf origin main
```

## Integrate with your tools

- [ ] [Set up project integrations](https://forge.univ-lyon1.fr/p2207683/tp9_graphe/-/settings/integrations)

## Collaborate with your team

- [ ] [Invite team members and collaborators](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [Create a new merge request](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [Automatically close issues from merge requests](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [Enable merge request approvals](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
- [ ] [Set auto-merge](https://docs.gitlab.com/ee/user/project/merge_requests/merge_when_pipeline_succeeds.html)

## Test and Deploy

# README

## Introduction
Ce code C++ est une implémentation d'un algorithme de recherche de flot maximal dans un graphe. L'algorithme utilisé est un Parcours en largeur pour trouver des chemins augmentants. Le graphe est construit à partir d'une image PGM, où chaque pixel est représenté comme un nœud du graphe.
Le but final est de binariser cette image , il créera donc un nouveau fichier qui s'appelle La_Notre.pgm . 
Les images manipulabes se trouvent dans data .
Pour modifier l'image de départ aller dans le main puis donner le nom de l'image dans le paramétre du constructeur du graphe .
## Contenu du Code
Le code est composé de plusieurs fonctions . Voici un aperçu des principales fonctionnalités :

### Logarithme népérien
La fonction `ln` calcule le logarithme népérien d'un nombre donné.

### Lecture et Sauvegarde de Fichier
Les fonctions `ouvrir` et `sauver` permettent respectivement de lire une image PGM à partir d'un fichier et de sauvegarder une image PGM résultante.

### Initialisation du Graphe
La classe `Graphe` est utilisée pour représenter le graphe. La fonction `InitVoisin` initialise les quatres voisins(Nord , Sud ; Est , Ouest)  de chaque pixel dans le graphe.

### Calcul des Capacités
La fonction `SetCap` modifie la capacité d'un arc entre deux pixels données en paramétres lors de son appel .

### Recherche de Chemin Augmentant
La fonction `ParcoursLargeur` utilise une recherche en largeur pour trouver des chemins augmentants dans le graphe. Et incrémenre le flot maximale .

### Calcul du Flot Minimal
La fonction `FlotMin` calcule le flot minimal le long d'un chemin augmentant et modifie le flot de chaque arc qui compose le schéma augmentant .

### Coupe du Graphe
La fonction `coupeGraphe` modifie l'intensité des pixels pour les mettre soit à 0 soit à 255 selon la capacité  entre la source et chaque pixel . 

### Construction du Graphe
Le constructeur de la classe `Graphe` initialise le graphe en lisant une image PGM, en initialisant les voisins et en calculant les capacités.

## Compilation
Pour compiler le code,
make clean 
make
./bin/main.out