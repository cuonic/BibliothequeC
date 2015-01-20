# Projet Bibliothèque - Structure de données
Par Liam JACK (G3)

## Fonctionalités

Notre programme permet de :

* Ajouter un lecteur
* Modifier l'adresse d'un lecteur
* Supprimer un lecteur
* Ajouter un ouvrage
* Supprimer un ouvrage
* Ajouter un emprunt
* Retourner un emprunt

## Les bibliothèques

Nous avons utilisé trois bibliothèques C afin de permettre le bon fonctionnement de notre programme :

* **stdio.h**
    Utilisée pour l'affichage à l'écran, la saisie au clavier, la lecture et l'écriture des fichiers.
* **stdlib.h**
    Utilisée pour les fonctions d'allocation de la memoire, la fonction `exit` pour quitter le programme.
* **string.h**
    Utilisée pour comparer et copier des chaines de caractères dans le programme.

## Les structures

Dans notre projet nous avons choisi d'utiliser plusieurs structures pour mieux stocker les informations. Nous avons sept structures :

* **Date**
    * `jour` (int) Le jour
    * `mois` (int) Le mois
    * `annee` (int) L'année
* **Adresse**
    * `numero` (int) Le numero de la rue
    * `rue` (char 50) Le nom de la rue
    * `codepostal` (int) Le code postal
    * `ville` (char 20) La ville
* **Emprunt**
    * `cote` (char 6) La cote du livre
    * `dateemprunt` (Date) La date quand le livre a été emprunté
* **Lecteur**
    * `numero` (int) Le numero de lecteur
    * `nom` (char 20) Le nom du lecteur
    * `prenom` (char 20) Le prénom du lecteur
    * `adresse` (Adresse) L'adresse du lecteur
    * `nbemprunts` (int) Le nombre d'emprunts en cours
    * `emprunts` (Emprunt *) Un tableau d'emprunts en cours
* **Booleen**
   C'est une structure qui permet d'avoir un booléen, soit `vrai` ou `faux`
* **Ouvrage**
    * `cote` (char 6) La cote du livre
    * `titre` (char 50) Le titre du livre
    * `categorie` (char 5) La categorie (Exemple : `BD`, `ROM`, `POL`)
    * `auteur` (char 50) L'auteur du livre
    * `estEmprunte` (Booleen) Permet de savoir si le livre est actuellement emprunté
    * `numLecteur` (int) Le numero de lecteur de l'emprunter si le livre est actuellement emprunté, sinon `0`
* **EmpruntRetourne**
    * `numlecteur` (int) Le numero de lecteur
    * `cote` (char 6) La cote du livre
    * `dateemprunt` (Date) Quand le livre a été emprunté
    * `dateretour` (Date) Quand le livre a été retourné

## Les fichiers

Notre programme stocke les informations dans trois fichiers entre deux executions.

* **lecteurs.don**
Ce fichier contient tous les lecteurs et leurs emprunts en cours.
* **ouvrages.don**
Ce fichier contient tous les ouvrages.
* **empruntsretournes.don**
Ce fichier contient tous les emprunts retournés.

## Les fonctions

Notre programme comporte au total 40 fonctions, nous avons fait le plus de fonctions possibles pour faciliter le debogage en cas d'erreur, pour pouvoir réutiliser ces fonctions à plusieurs endroits dans le programme sans reécrire le code et pour rendre le programme plus compréhensible.

* **saisirLecteur**
Permet de saisir un lecteur au clavier, et retourne une structure Lecteur. Elle est utilisée par la fonction `ajouterLecteur`.
* **saisirOuvrage**
Permet de saisir un ouvrage au clavier, et retourne une structure Ouvrage. Elle est utilisée par la fonction `ajouterOuvrage`.
* **saisirAdresse**
Permet de saisir une adresse au clavier, et retourne une structure Adresse. Elle est utilisée par les fonctions `saisirLecteur` et `modifierAdresse`.
* **saisirDate**
Permet de saisir une date au clavier, et retourne une structure Date. Elle est utilisée par les fonctions `ajouterEmprunt` et `retournerEmprunt`.
* **afficherLecteurs**
Permet d'afficher un tableau de lecteurs. Elle est utilisée par la fonction `global`.
* **afficherLecteur**
Permet d'afficher un lecteur à l'écran. Elle est utilisée par la fonction `afficherLecteurs`.
* **afficherAdresse**
Permet d'afficher une adresse à l'écran. Elle est utilisée par les fonctions `modifierAdresse` et `afficherLecteur`.
* **afficherEmprunts**
Permet d'afficher un tableau d'emprunts. Elle est utilisée par les fonction `afficherLecteur` et `global`.
* **afficherEmprunt**
Permet d'afficher un emprunt à l'écran. Elle est utilisée par la fonction `afficherEmprunt`.
* **afficherEmpruntsRetournes**
Permet d'afficher un tableau d'emprunts retournés. Elle est utilisée par la fonction `global`.
* **afficherEmpruntRetourne**
Permet d'afficher un emprunt retourné à l'écran. Elle est utilisée par la fonction `afficherEmpruntsRetournes`.
* **afficherDate**
Permet d'afficher une date à l'écran. Elle est utilisée par les fonctions `afficherEmprunt` et `afficherEmpruntRetourne`.
* **afficherOuvrages**
Permet d'afficher un tableau d'ouvrages. Elle est utilisée par la fonction `global`.
* **afficherOuvrage**
Permet d'afficher un ouvrage à l'écran. Elle est utilisée par les fonctions `afficherOuvrages` et `afficherOuvrage2`.
* **lireLecteurs**
Permet de lire les lecteurs à partir d'un fichier. Elle retourne un tableau de lecteurs et est utilisée par la fonction `global`.
* **lireLecteur**
Permet de lire un lecteur à partir d'un fichier. Elle retourne une structure Lecteur et est utilisée par la fonction `lireLecteurs`.
* **lireAdresse**
Permet de lire une adresse à partir d'un fichier. Elle retourne une structure Adresse et est utilisée par la fonction `lireLecteur`.
* **lireEmprunts**
Permet de lire les emprunts à partir d'un fichier. Elle retourne un tableau d'emprunts et est utilisée par la fonction `lireLecteur`.
* **lireEmprunt**
Permet de lire un emprunt à partir d'un fichier. Elle retourne une stucture Emprunt et est utilisée par la fonction `lireEmprunts`.
* **lireEmpruntsRetournes**
Permet de lire les emprunts retournés à partir d'un fichier. Elle retourne un tableau d'emprunts retournés et est utilisée par la fonction `global`.
* **lireEmpruntRetourne**
Permet de lire un emprunt retourné à partir d'un fichier. Elle retourne une structure EmpruntRetourne et est utilisée par la fonction `lireEmpruntsRetournes`.
* **lireDate**
Permet de lire une date à partir d'un fichier. Elle retourne une structure Date et est utilisée par les fonctions `lireEmprunt` et `lireEmpruntRetourne`.
* **lireOuvrages**
Permet de lire les ouvrages à partir d'un fichier. Elle retourne un tableau d'ouvrages et est utilisée par la fonction `global`.
* **lireOuvrage**
Permet de lire un ouvrage à partir d'un fichier. Elle retourne une structure Ouvrage et est utilisée par la fonction `lireOuvrages`.
* **afficherMenu**
Permet d'afficher le menu principal à l'écran. Elle est utilisée par la fonction `global`.
* **global**
C'est la fonction principale du programme permettant l'ouverture des fichiers, le chargement des differents tableaux, l'affichage du menu et la gestion des choix de l'utilisateur ainsi que la sauvegarde des tableaux dans les fichiers en quittant le programme. Elle est utilisée par la fonction `main`.
* **ajouterLecteur**
Permet d'ajouter un lecteur au tableau de lecteurs. Elle est utilisée par la fonction `global`.
* **rechercheLecteur**
Permet de rechercher un lecteur par numero de lecteur dans le tableau des lecteurs. Elle retourne l'indice du lecteur dans le tableau si il existe, ou `-1` si il n'a pas été trouvé et est utilisée par les fonctions `afficherLecteur2`, `modifierAdresse`, `ajouterEmprunt`, `supprimerLecteur`, `retournerEmprunt` et `ajouterLecteur`.
* **afficherLecteur2**
Permet d'afficher un lecteur à l'écran en specifiant le numero de lecteur. Elle est utilisée par la fonction `global`.
* **modifierAdresse**
Permet de modifier l'adresse d'un lecteur en specifiant le numero de lecteur. Elle est utilisée par la fonction `global`.
* **ajouterEmprunt**
Permet d'ajouter un emprunt au tableau des emprunts d'un lecteur. Elle est utilisée par la fonction `global`.
* **supprimerLecteur**
Permet de supprimer un lecteur en specifiant le numero de lecteur. Elle est utilisée par la fonction `global`.
* **ajouterOuvrage**
Permet d'ajouter un ouvrage au tableau des ouvrages. Elle est utilisée par la fonction `global`.
* **rechercheOuvrage**
Permet de rechercher un ouvrage par cote dans le tableau des ouvrages. Elle retourne l'indice de l'ouvrage dans le tableau si il existe, ou `-1` si il n'a pas été trouvé et est utilisée par les fonctions `afficherOuvrage2`, `supprimerOuvrage`, `retournerEmprunt`, `lireEmprunt` et `ajouterEmprunt`.
* **afficherOuvrage2**
Permet d'afficher un ouvrage à l'écran en specifiant la cote. Elle est utilisée par la fonction `global`.
* **supprimerOuvrage**
Permet de supprimer un ouvrage en specifiant la cote. Elle est utilisée par la fonction `global`.
* **rechercheEmprunt**
Permet de rechercher un emprunt dans un tableau des emprunts d'un lecteur en specifiant la cote. Elle retourne l'indice de l'emprunt dans le tableau si il existe, ou `-1` si il n'a pas été trouvé et est utilisée par la fonction `retournerEmprunt`.
* **retournerEmprunt**
Permet de prendre un emprunt en cours d'un lecteur et de le mettre dans le tableau des emprunts retournés. Elle est utilisée par la fonction `global`.

## Fonctionnement

C'est la fonction `global` qui gère une grande partie du programme, c'est elle qui est executée au lancement du programme jusqu'à la fin de l'execution. La fonction commence par ouvrir les fichiers des lecteurs, des ouvrages et des emprunts retournés en lecture et procede à la lecture des fichiers pour ajouter des lecteurs au tableau `tabLecteur`, des ouvrages au tableau `tabOuvrage` et des emprunts retournés dans `tabEmpruntRetourne`. La fonction ferme ensuite les trois fichiers et affiche un menu à l'utilisateur.

Chaque tableau est alloué dynamiquement, c'est-à-dire que la taille du tableau est augmenté avec chaque nouvel élément trouvé dans un fichier ou ajouté avec une fonction, grâce à `realloc`.

L'utilisateur peut saisir un choix au clavier pour choisir l'operation qu'il va effectuer par la suite. La fonction interprete le choix pour savoir quelle fonction executer. Si l'utilisateur tape `0` on sort de la boucle du menu et on commence l'arrêt du programme.

Avant la fin de l'execution du programme la fonction va sauvegarder les tableaux dans les fichiers en ouvrant les trois fichiers en écriture, en écrivant les differents tableaux dans leur fichier respectif en ecrasant les données existantes. Ensuite la fonction fait appel à `exit(0)` pour terminer le programme et en indiquant au système que le programme s'est executé correctement.

## Verifications

Des verifications sont faites à plusieurs endroits dans le programme pour eviter de casser des relations entre deux tableaux ou des saisies erronnées.

* Un lecteur ne peut pas être supprimé si il a encore des emprunts en cours, sinon le livre physique peut disparaitre.
* Un ouvrage ne peut pas être supprimé si il est actuellement emprunté par un lecteur.
* Un emprunt ne peut pas être ajouté si la cote du livre n'est pas trouvée dans le tableau des ouvrages
* Un lecteur ne peut pas être ajouté si le numero de lecteur existe déjà.
* Un ouvrage ne peut pas être ajouté si la cote du livre existe déjà.
* La cote du livre doit faire 5 caractères.
* Le titre du livre doit faire au moins 5 caractères.
* La catégorie du livre doit faire moins de 5 caractères.
* Le nom de l'auteur doit faire au moins 5 caractères.
* Le jour de la date doit être compris entre 1 et 31.
* Le mois de la date doit être compris entre 1 et 12.
* L'année doit être comprise entre 2000 et 2020.
* Lors du chargement des emprunts d'un lecteur on verifie si l'ouvrage existe bien, sinon on arrête le programme.
* Le programme verifie si les fichiers ont été ouverts correctement avant de lire / écrire dedans.
* Le programme verifie si `malloc` et `realloc` ont bien réussi à allouer l'espace memoire avant d'utiliser les tableaux.
* Un lecteur peut avoir un maximum de trois emprunts.
* Un emprunt ne peut pas être retourné si l'ouvrage n'est pas actuellement emprunté.
* Un emprunt ne peut pas être retourné si la cote du livre ou le numero de lecteur est incorrect.

## Difficultés rencontés

Nous avons eu des difficultés avec les chaines de caractère, à un moment, lors de la lecture de l'ouvrage on lisait une cote de 5 caractères dans un `char[5]` avec la fonction `fscanf`. En l'affichant à l'écran on voit bien la chaine saisie. Ensuite nous procedons à la lecture du nom de l'ouvrage avec `fgets`, le titre est lu correctement, on ferme le fichier. Plus loin dans le programme on affiche la cote du livre : `ABCDETintin au Quebec`. Le titre s'était concatené à la cote.

Comme on essayait de mettre une chaine de 5 caractères dans un `char[5]` il n'y avait pas la place pour la fin de la chaine (`\0`) et donc la cote était devenu la cote, plus la variable qui suivait dans la memoire, jusqu'à trouver un `\0`.