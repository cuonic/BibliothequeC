# Projet Biblioth�que - Structure de donn�es
Par Liam JACK (G3)

## Fonctionalit�s

Notre programme permet de :

* Ajouter un lecteur
* Modifier l'adresse d'un lecteur
* Supprimer un lecteur
* Ajouter un ouvrage
* Supprimer un ouvrage
* Ajouter un emprunt
* Retourner un emprunt

## Les biblioth�ques

Nous avons utilis� trois biblioth�ques C afin de permettre le bon fonctionnement de notre programme :

* **stdio.h**
    Utilis�e pour l'affichage � l'�cran, la saisie au clavier, la lecture et l'�criture des fichiers.
* **stdlib.h**
    Utilis�e pour les fonctions d'allocation de la memoire, la fonction `exit` pour quitter le programme.
* **string.h**
    Utilis�e pour comparer et copier des chaines de caract�res dans le programme.

## Les structures

Dans notre projet nous avons choisi d'utiliser plusieurs structures pour mieux stocker les informations. Nous avons sept structures :

* **Date**
    * `jour` (int) Le jour
    * `mois` (int) Le mois
    * `annee` (int) L'ann�e
* **Adresse**
    * `numero` (int) Le numero de la rue
    * `rue` (char 50) Le nom de la rue
    * `codepostal` (int) Le code postal
    * `ville` (char 20) La ville
* **Emprunt**
    * `cote` (char 6) La cote du livre
    * `dateemprunt` (Date) La date quand le livre a �t� emprunt�
* **Lecteur**
    * `numero` (int) Le numero de lecteur
    * `nom` (char 20) Le nom du lecteur
    * `prenom` (char 20) Le pr�nom du lecteur
    * `adresse` (Adresse) L'adresse du lecteur
    * `nbemprunts` (int) Le nombre d'emprunts en cours
    * `emprunts` (Emprunt *) Un tableau d'emprunts en cours
* **Booleen**
   C'est une structure qui permet d'avoir un bool�en, soit `vrai` ou `faux`
* **Ouvrage**
    * `cote` (char 6) La cote du livre
    * `titre` (char 50) Le titre du livre
    * `categorie` (char 5) La categorie (Exemple : `BD`, `ROM`, `POL`)
    * `auteur` (char 50) L'auteur du livre
    * `estEmprunte` (Booleen) Permet de savoir si le livre est actuellement emprunt�
    * `numLecteur` (int) Le numero de lecteur de l'emprunter si le livre est actuellement emprunt�, sinon `0`
* **EmpruntRetourne**
    * `numlecteur` (int) Le numero de lecteur
    * `cote` (char 6) La cote du livre
    * `dateemprunt` (Date) Quand le livre a �t� emprunt�
    * `dateretour` (Date) Quand le livre a �t� retourn�

## Les fichiers

Notre programme stocke les informations dans trois fichiers entre deux executions.

* **lecteurs.don**
Ce fichier contient tous les lecteurs et leurs emprunts en cours.
* **ouvrages.don**
Ce fichier contient tous les ouvrages.
* **empruntsretournes.don**
Ce fichier contient tous les emprunts retourn�s.

## Les fonctions

Notre programme comporte au total 40 fonctions, nous avons fait le plus de fonctions possibles pour faciliter le debogage en cas d'erreur, pour pouvoir r�utiliser ces fonctions � plusieurs endroits dans le programme sans re�crire le code et pour rendre le programme plus compr�hensible.

* **saisirLecteur**
Permet de saisir un lecteur au clavier, et retourne une structure Lecteur. Elle est utilis�e par la fonction `ajouterLecteur`.
* **saisirOuvrage**
Permet de saisir un ouvrage au clavier, et retourne une structure Ouvrage. Elle est utilis�e par la fonction `ajouterOuvrage`.
* **saisirAdresse**
Permet de saisir une adresse au clavier, et retourne une structure Adresse. Elle est utilis�e par les fonctions `saisirLecteur` et `modifierAdresse`.
* **saisirDate**
Permet de saisir une date au clavier, et retourne une structure Date. Elle est utilis�e par les fonctions `ajouterEmprunt` et `retournerEmprunt`.
* **afficherLecteurs**
Permet d'afficher un tableau de lecteurs. Elle est utilis�e par la fonction `global`.
* **afficherLecteur**
Permet d'afficher un lecteur � l'�cran. Elle est utilis�e par la fonction `afficherLecteurs`.
* **afficherAdresse**
Permet d'afficher une adresse � l'�cran. Elle est utilis�e par les fonctions `modifierAdresse` et `afficherLecteur`.
* **afficherEmprunts**
Permet d'afficher un tableau d'emprunts. Elle est utilis�e par les fonction `afficherLecteur` et `global`.
* **afficherEmprunt**
Permet d'afficher un emprunt � l'�cran. Elle est utilis�e par la fonction `afficherEmprunt`.
* **afficherEmpruntsRetournes**
Permet d'afficher un tableau d'emprunts retourn�s. Elle est utilis�e par la fonction `global`.
* **afficherEmpruntRetourne**
Permet d'afficher un emprunt retourn� � l'�cran. Elle est utilis�e par la fonction `afficherEmpruntsRetournes`.
* **afficherDate**
Permet d'afficher une date � l'�cran. Elle est utilis�e par les fonctions `afficherEmprunt` et `afficherEmpruntRetourne`.
* **afficherOuvrages**
Permet d'afficher un tableau d'ouvrages. Elle est utilis�e par la fonction `global`.
* **afficherOuvrage**
Permet d'afficher un ouvrage � l'�cran. Elle est utilis�e par les fonctions `afficherOuvrages` et `afficherOuvrage2`.
* **lireLecteurs**
Permet de lire les lecteurs � partir d'un fichier. Elle retourne un tableau de lecteurs et est utilis�e par la fonction `global`.
* **lireLecteur**
Permet de lire un lecteur � partir d'un fichier. Elle retourne une structure Lecteur et est utilis�e par la fonction `lireLecteurs`.
* **lireAdresse**
Permet de lire une adresse � partir d'un fichier. Elle retourne une structure Adresse et est utilis�e par la fonction `lireLecteur`.
* **lireEmprunts**
Permet de lire les emprunts � partir d'un fichier. Elle retourne un tableau d'emprunts et est utilis�e par la fonction `lireLecteur`.
* **lireEmprunt**
Permet de lire un emprunt � partir d'un fichier. Elle retourne une stucture Emprunt et est utilis�e par la fonction `lireEmprunts`.
* **lireEmpruntsRetournes**
Permet de lire les emprunts retourn�s � partir d'un fichier. Elle retourne un tableau d'emprunts retourn�s et est utilis�e par la fonction `global`.
* **lireEmpruntRetourne**
Permet de lire un emprunt retourn� � partir d'un fichier. Elle retourne une structure EmpruntRetourne et est utilis�e par la fonction `lireEmpruntsRetournes`.
* **lireDate**
Permet de lire une date � partir d'un fichier. Elle retourne une structure Date et est utilis�e par les fonctions `lireEmprunt` et `lireEmpruntRetourne`.
* **lireOuvrages**
Permet de lire les ouvrages � partir d'un fichier. Elle retourne un tableau d'ouvrages et est utilis�e par la fonction `global`.
* **lireOuvrage**
Permet de lire un ouvrage � partir d'un fichier. Elle retourne une structure Ouvrage et est utilis�e par la fonction `lireOuvrages`.
* **afficherMenu**
Permet d'afficher le menu principal � l'�cran. Elle est utilis�e par la fonction `global`.
* **global**
C'est la fonction principale du programme permettant l'ouverture des fichiers, le chargement des differents tableaux, l'affichage du menu et la gestion des choix de l'utilisateur ainsi que la sauvegarde des tableaux dans les fichiers en quittant le programme. Elle est utilis�e par la fonction `main`.
* **ajouterLecteur**
Permet d'ajouter un lecteur au tableau de lecteurs. Elle est utilis�e par la fonction `global`.
* **rechercheLecteur**
Permet de rechercher un lecteur par numero de lecteur dans le tableau des lecteurs. Elle retourne l'indice du lecteur dans le tableau si il existe, ou `-1` si il n'a pas �t� trouv� et est utilis�e par les fonctions `afficherLecteur2`, `modifierAdresse`, `ajouterEmprunt`, `supprimerLecteur`, `retournerEmprunt` et `ajouterLecteur`.
* **afficherLecteur2**
Permet d'afficher un lecteur � l'�cran en specifiant le numero de lecteur. Elle est utilis�e par la fonction `global`.
* **modifierAdresse**
Permet de modifier l'adresse d'un lecteur en specifiant le numero de lecteur. Elle est utilis�e par la fonction `global`.
* **ajouterEmprunt**
Permet d'ajouter un emprunt au tableau des emprunts d'un lecteur. Elle est utilis�e par la fonction `global`.
* **supprimerLecteur**
Permet de supprimer un lecteur en specifiant le numero de lecteur. Elle est utilis�e par la fonction `global`.
* **ajouterOuvrage**
Permet d'ajouter un ouvrage au tableau des ouvrages. Elle est utilis�e par la fonction `global`.
* **rechercheOuvrage**
Permet de rechercher un ouvrage par cote dans le tableau des ouvrages. Elle retourne l'indice de l'ouvrage dans le tableau si il existe, ou `-1` si il n'a pas �t� trouv� et est utilis�e par les fonctions `afficherOuvrage2`, `supprimerOuvrage`, `retournerEmprunt`, `lireEmprunt` et `ajouterEmprunt`.
* **afficherOuvrage2**
Permet d'afficher un ouvrage � l'�cran en specifiant la cote. Elle est utilis�e par la fonction `global`.
* **supprimerOuvrage**
Permet de supprimer un ouvrage en specifiant la cote. Elle est utilis�e par la fonction `global`.
* **rechercheEmprunt**
Permet de rechercher un emprunt dans un tableau des emprunts d'un lecteur en specifiant la cote. Elle retourne l'indice de l'emprunt dans le tableau si il existe, ou `-1` si il n'a pas �t� trouv� et est utilis�e par la fonction `retournerEmprunt`.
* **retournerEmprunt**
Permet de prendre un emprunt en cours d'un lecteur et de le mettre dans le tableau des emprunts retourn�s. Elle est utilis�e par la fonction `global`.

## Fonctionnement

C'est la fonction `global` qui g�re une grande partie du programme, c'est elle qui est execut�e au lancement du programme jusqu'� la fin de l'execution. La fonction commence par ouvrir les fichiers des lecteurs, des ouvrages et des emprunts retourn�s en lecture et procede � la lecture des fichiers pour ajouter des lecteurs au tableau `tabLecteur`, des ouvrages au tableau `tabOuvrage` et des emprunts retourn�s dans `tabEmpruntRetourne`. La fonction ferme ensuite les trois fichiers et affiche un menu � l'utilisateur.

Chaque tableau est allou� dynamiquement, c'est-�-dire que la taille du tableau est augment� avec chaque nouvel �l�ment trouv� dans un fichier ou ajout� avec une fonction, gr�ce � `realloc`.

L'utilisateur peut saisir un choix au clavier pour choisir l'operation qu'il va effectuer par la suite. La fonction interprete le choix pour savoir quelle fonction executer. Si l'utilisateur tape `0` on sort de la boucle du menu et on commence l'arr�t du programme.

Avant la fin de l'execution du programme la fonction va sauvegarder les tableaux dans les fichiers en ouvrant les trois fichiers en �criture, en �crivant les differents tableaux dans leur fichier respectif en ecrasant les donn�es existantes. Ensuite la fonction fait appel � `exit(0)` pour terminer le programme et en indiquant au syst�me que le programme s'est execut� correctement.

## Verifications

Des verifications sont faites � plusieurs endroits dans le programme pour eviter de casser des relations entre deux tableaux ou des saisies erronn�es.

* Un lecteur ne peut pas �tre supprim� si il a encore des emprunts en cours, sinon le livre physique peut disparaitre.
* Un ouvrage ne peut pas �tre supprim� si il est actuellement emprunt� par un lecteur.
* Un emprunt ne peut pas �tre ajout� si la cote du livre n'est pas trouv�e dans le tableau des ouvrages
* Un lecteur ne peut pas �tre ajout� si le numero de lecteur existe d�j�.
* Un ouvrage ne peut pas �tre ajout� si la cote du livre existe d�j�.
* La cote du livre doit faire 5 caract�res.
* Le titre du livre doit faire au moins 5 caract�res.
* La cat�gorie du livre doit faire moins de 5 caract�res.
* Le nom de l'auteur doit faire au moins 5 caract�res.
* Le jour de la date doit �tre compris entre 1 et 31.
* Le mois de la date doit �tre compris entre 1 et 12.
* L'ann�e doit �tre comprise entre 2000 et 2020.
* Lors du chargement des emprunts d'un lecteur on verifie si l'ouvrage existe bien, sinon on arr�te le programme.
* Le programme verifie si les fichiers ont �t� ouverts correctement avant de lire / �crire dedans.
* Le programme verifie si `malloc` et `realloc` ont bien r�ussi � allouer l'espace memoire avant d'utiliser les tableaux.
* Un lecteur peut avoir un maximum de trois emprunts.
* Un emprunt ne peut pas �tre retourn� si l'ouvrage n'est pas actuellement emprunt�.
* Un emprunt ne peut pas �tre retourn� si la cote du livre ou le numero de lecteur est incorrect.

## Difficult�s rencont�s

Nous avons eu des difficult�s avec les chaines de caract�re, � un moment, lors de la lecture de l'ouvrage on lisait une cote de 5 caract�res dans un `char[5]` avec la fonction `fscanf`. En l'affichant � l'�cran on voit bien la chaine saisie. Ensuite nous procedons � la lecture du nom de l'ouvrage avec `fgets`, le titre est lu correctement, on ferme le fichier. Plus loin dans le programme on affiche la cote du livre : `ABCDETintin au Quebec`. Le titre s'�tait concaten� � la cote.

Comme on essayait de mettre une chaine de 5 caract�res dans un `char[5]` il n'y avait pas la place pour la fin de la chaine (`\0`) et donc la cote �tait devenu la cote, plus la variable qui suivait dans la memoire, jusqu'� trouver un `\0`.