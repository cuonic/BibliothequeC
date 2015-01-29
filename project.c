#include "project.h"

/*
* Fonction pour saisir un nouveau lecteur
*/

Lecteur saisirLecteur(void)
{
	// On initialise un lecteur l

	Lecteur l;

	// Saisie du numero de lecteur

	printf("Numero de lecteur: ");
	scanf("%d%*c", &l.numero);

	// Saisie du nom

	printf("Nom: ");
	fgets(l.nom, 20, stdin);
	l.nom[strlen(l.nom) - 1] = '\0';

	// Saisie du prenom

	printf("Prenom: ", 20, stdin);
	fgets(l.prenom, 20, stdin);
	l.nom[strlen(l.prenom) - 1] = '\0';

	// On appelle la fonction pour saisir l'adresse du lecteur

	l.adresse = saisirAdresse();

	// Initialisation du tableau d'emprunts

	l.nbemprunts = 0;
	l.emprunts = NULL;

	// On retourne le lecteur

	return l;
}

/*
 * Fonction pour saisir un ouvrage
 */

Ouvrage saisirOuvrage(void)
{
	// On initialise un ouvrage o

	Ouvrage o;

	// Saisie de la cote du livre

	while(1)
	{
		printf("Cote: ");
		scanf("%s%*c", o.cote);

		if(strlen(o.cote) != 5)
			printf("[ERREUR] La cote du livre doit faire 5 caracteres.\n");
		else
			break;
	}

	// Saisie du titre

	while(1)
	{
		printf("Titre: ");
		fgets(o.titre, 50, stdin);
		o.titre[strlen(o.titre) - 1] = '\0';

		if(strlen(o.titre) < 5)
			printf("[ERREUR] Le titre doit faire au moins 5 caracteres.\n");
		else
			break;
	}

	// Saisie de la categorie

	while(1)
	{
		printf("Categorie: ");
		scanf("%s%*c", o.categorie);

		if(strlen(o.categorie) > 5)
			printf("[ERREUR] La categorie doit faire moins de 5 caracteres.\n");
		else
			break;
	}

	// Saisie de l'auteur

	while(1)
	{
		printf("Auteur: ");
		fgets(o.auteur, 50, stdin);
		o.auteur[strlen(o.auteur) - 1] = '\0';

		if(strlen(o.auteur) < 5)
			printf("[ERREUR] Le nom de l'auteur doit faire au moins 5 caracteres.\n");
		else
			break;
	}

	o.estEmprunte = faux;
	o.numLecteur = 0;

	return o;
}

/*
* Fonction pour saisir une adresse pour un lecteur
*/

Adresse saisirAdresse(void)
{
	// On initialise une adresse a

	Adresse a;

	// Saisie du numero de la rue

	printf("Numero de la rue: ");
	scanf("%d%*c", &a.numero);

	// Saisie du nom de la rue

	printf("Nom de la rue: ");
	fgets(a.rue, 50, stdin);
	a.rue[strlen(a.rue) - 1] = '\0';

	// Saisie du code postal

    printf("Code postal: ");
    scanf("%d%*c", &a.codepostal);

	// Saisie de la ville

	printf("Ville: ");
	fgets(a.ville, 20, stdin);
	a.ville[strlen(a.ville) - 1] = '\0';

	// On retourne l'adresse

	return a;
}

/*
* Fonction pour saisir une date
*/

Date saisirDate(void)
{
	Date d;
	Booleen datevalide = faux;

	while(datevalide == faux)
	{
		printf("Date (jj/mm/aaaa) : ");

		scanf("%d/%d/%d%*c", &d.jour, &d.mois, &d.annee);

		if(d.jour < 1 || d.jour > 31)
		{
			printf("Jour invalide.\n");
		}

		else if(d.mois < 1 || d.mois > 12)
		{
			printf("Mois invalide.\n");
		}

		else if(d.annee < 2000 || d.annee > 2020)
		{
			printf("Annee invalide.\n");
		}

		else
		{
			datevalide = vrai;
		}
	}

	return d;
}

/*
* Fonction pour afficher un tableau de lecteurs
*/

void afficherLecteurs(Lecteur *tabLecteur, int nbLecteur)
{
    int i;

    for(i = 0; i < nbLecteur; i++)
    {
        afficherLecteur(tabLecteur[i]);
        printf("==========================\n");
    }
}

/*
* Fonction pour afficher un lecteur
*/

void afficherLecteur(Lecteur l)
{
	printf("\nInformations:\n");
	printf("Numero de lecteur: %d\n", l.numero);
	printf("Nom: %s\n", l.nom);
	printf("Prenom: %s\n", l.prenom);

	afficherAdresse(l.adresse);

	printf("Nombre d'emprunts: %d\n", l.nbemprunts);

	afficherEmprunts(l.emprunts, l.nbemprunts);
}

/*
* Fonction pour afficher une adresse
*/

void afficherAdresse(Adresse a)
{
	printf("\nAdresse:\n");
	printf("%d ", a.numero);
	printf("%s\n", a.rue);
	printf("%d ", a.codepostal);
	printf("%s\n", a.ville);
}

/*
* Fonction pour afficher les emprunts d'un lecteur
*/

void afficherEmprunts(Emprunt *tabEmprunt, int nbEmprunt)
{
    int i;

    printf("\nEmprunts: \n");

    if(nbEmprunt == 0)
    {
        printf("Aucun\n");
    }
    else
    {
        printf("Cote:\t\tDate d'emprunt:\n");

        for(i = 0; i < nbEmprunt; i++)
        {
            afficherEmprunt(tabEmprunt[i]);
        }
    }
}

/*
* Fonction pour afficher un emprunt
*/

void afficherEmprunt(Emprunt e)
{
	printf("%s\t\t", e.cote);

	afficherDate(e.dateemprunt);

	printf("\n");
}

/*
 * Fonction pour afficher un tableau d'emprunts retournés
 */

void afficherEmpruntsRetournes(EmpruntRetourne *tabEmpruntRetourne, int nbEmpruntRetourne)
{
	int i;

    printf("\nEmprunts Retournés: \n");

    if(nbEmpruntRetourne == 0)
    {
        printf("Aucun emprunt retourné.\n");
    }
    else
    {
        printf("Numero Lecteur:\t\tCote:\t\tDate d'emprunt:\t\tDate de retour:\n");

        for(i = 0; i < nbEmpruntRetourne; i++)
        {
            afficherEmpruntRetourne(tabEmpruntRetourne[i]);
        }
    }
}

/*
 * Fonction pour afficher un emprunt retourné
 */

void afficherEmpruntRetourne(EmpruntRetourne e)
{
	printf("%d\t\t\t%s\t\t", e.numlecteur, e.cote);

	afficherDate(e.dateemprunt);

	printf("\t\t");

	afficherDate(e.dateretour);

	printf("\n");
}

/*
* Fonction pour afficher une date
*/

void afficherDate(Date d)
{
	printf("%d/%d/%d", d.jour, d.mois, d.annee);
}

/*
* Fonction pour afficher un tableau d'ouvrages
*/

void afficherOuvrages(Ouvrage *tabOuvrage, int nbOuvrage)
{
    int i;

    for(i = 0; i < nbOuvrage; i++)
    {
        afficherOuvrage(tabOuvrage[i]);
        printf("==========================\n");
    }
}

/*
* Fonction pour afficher un ouvrage
*/

void afficherOuvrage(Ouvrage o)
{
    printf("Cote: %s\n", o.cote);
    printf("Titre: %s\n", o.titre);
    printf("Categorie: %s\n", o.categorie);
    printf("Auteur: %s\n", o.auteur);
}

/*
* Fonction pour lire les lecteurs à partir d'un fichier
*/

Lecteur * lireLecteurs(FILE *flot, int *nbLecteur, Ouvrage *tabOuvrage, int nbOuvrage)
{
    Lecteur *tabLecteur, *aux, l;

    tabLecteur = (Lecteur *) malloc(sizeof(Lecteur));

    if(tabLecteur == NULL)
    {
        printf("Erreur malloc. \n");
        exit(1);
    }

    l = lireLecteur(flot, tabOuvrage, nbOuvrage);

    while(!feof(flot))
    {
        tabLecteur[*nbLecteur] = l;
        (*nbLecteur)++;

        aux = (Lecteur *) realloc(tabLecteur, (*nbLecteur + 1) * sizeof(Lecteur));

        if(aux == NULL)
        {
            printf("Erreur realloc. \n");
            exit(1);
        }

        tabLecteur = aux;

        l = lireLecteur(flot, tabOuvrage, nbOuvrage);
    }


    return tabLecteur;
}

/*
* Fonction pour lire un lecteur à partir d'un fichier
*/

Lecteur lireLecteur(FILE *flot, Ouvrage *tabOuvrage, int nbOuvrage)
{
	Lecteur l;

	// Lecture du numero de lecteur

	fscanf(flot, "%d%*c", &l.numero);

	// Lecture du nom

	fgets(l.nom, 20, flot);
	l.nom[strlen(l.nom) - 1] = '\0';

	// Lecture du prénom

	fgets(l.prenom, 20, flot);
	l.nom[strlen(l.prenom) - 1] = '\0';

	// Lecture de l'adresse

	l.adresse = lireAdresse(flot);

	// Lecture du nombre d'emprunts

	fscanf(flot, "%d%*c", &l.nbemprunts);

	// Lecture des emprunts

	l.emprunts = lireEmprunts(flot, l.nbemprunts, tabOuvrage, nbOuvrage, l.numero);

	return l;
}

/*
* Fonction pour lire une adresse à partir d'un fichier
*/

Adresse lireAdresse(FILE *flot)
{
    Adresse a;

    // Lecture du numero de la rue

    fscanf(flot, "%d%*c", &a.numero);

    // Lecture du nom de la rue

    fgets(a.rue, 50, flot);
	a.rue[strlen(a.rue) - 1] = '\0';

	// Lecture du code postal

	fscanf(flot, "%d%*c", &a.codepostal);

	// Lecture de la ville

	fgets(a.ville, 20, flot);
	a.ville[strlen(a.ville) - 1] = '\0';

	return a;
}

/*
* Fonction pour lire les emprunts d'un lecteur à partir d'un fichier
*/

Emprunt * lireEmprunts(FILE *flot, int nbEmprunt, Ouvrage *tabOuvrage, int nbOuvrage, int numLecteur)
{
    Emprunt *tab, e;
    int i;

    tab = (Emprunt *) malloc(nbEmprunt * sizeof(Emprunt));

    if(tab == NULL)
    {
        printf("Erreur malloc. \n");
        exit(1);
    }

    for(i = 0; i < nbEmprunt; i++)
    {
        tab[i] = lireEmprunt(flot, tabOuvrage, nbOuvrage, numLecteur);
    }

    return tab;
}

/*
* Fonction pour lire un emprunt d'un lecteur à partir d'un fichier
*/

Emprunt lireEmprunt(FILE *flot, Ouvrage *tabOuvrage, int nbOuvrage, int numLecteur)
{
    Emprunt e;
    int i;

    // Lecture de la cote du livre

    fscanf(flot, "%s%*c", e.cote);
    printf("%s\n", e.cote);

    // Verification de la cote du livre

    i = rechercheOuvrage(tabOuvrage, nbOuvrage, e.cote);

    if(i == -1)
    {
        //printf("%s\n", e.cote);
		printf("[ERREUR] Cote ouvrage inexistant.\n");
		exit(1);
	}

	tabOuvrage[i].estEmprunte = vrai;
	tabOuvrage[i].numLecteur = numLecteur;

    // Lecture de la date d'emprunt

    e.dateemprunt = lireDate(flot);

    return e;
}

/*
 * Fonction pour lire les emprunts retournés à partir d'un fichier
 */

EmpruntRetourne * lireEmpruntsRetournes(FILE *flot, int *nbEmpruntRetourne)
{
	EmpruntRetourne *tabEmpruntRetourne, *aux, e;

    tabEmpruntRetourne = (EmpruntRetourne *) malloc(sizeof(EmpruntRetourne));

    if(tabEmpruntRetourne == NULL)
    {
        printf("Erreur malloc. \n");
        exit(1);
    }

    e = lireEmpruntRetourne(flot);

    while(!feof(flot))
    {
        tabEmpruntRetourne[*nbEmpruntRetourne] = e;
        (*nbEmpruntRetourne)++;

        aux = (EmpruntRetourne *) realloc(tabEmpruntRetourne, (*nbEmpruntRetourne + 1) * sizeof(EmpruntRetourne));

        if(aux == NULL)
        {
            printf("Erreur realloc. \n");
            exit(1);
        }

        tabEmpruntRetourne = aux;

        e = lireEmpruntRetourne(flot);
    }


    return tabEmpruntRetourne;
}

/*
 * Fonction pour lire un emprunt retourné à partir d'un fichier
 */

EmpruntRetourne lireEmpruntRetourne(FILE *flot)
{
	EmpruntRetourne e;

	// Lecture du numero du lecteur

	fscanf(flot, "%d%*c", &e.numlecteur);

	// Lecture de la cote du livre

	fscanf(flot, "%s%*c", e.cote);

	// Lecture de la date d'emprunt

	e.dateemprunt = lireDate(flot);

	// Lecture de la date de retour

	e.dateretour = lireDate(flot);

	return e;
}

/*
* Fonction pour lire une date à partir d'un fichier
*/

Date lireDate(FILE *flot)
{
    Date d;

    // Lecture de la date

    fscanf(flot, "%d/%d/%d", &d.jour, &d.mois, &d.annee);

    return d;
}

/*
* Fonction pour lire les ouvrages à partir d'un fichier et les retourner sous forme de tableau
*/

Ouvrage * lireOuvrages(FILE *flot, int *nbOuvrage)
{
    Ouvrage *tabOuvrage, *aux, o;

    tabOuvrage = (Ouvrage *) malloc(sizeof(Ouvrage));

    if(tabOuvrage == NULL)
    {
        printf("Erreur malloc. \n");
        exit(1);
    }

    o = lireOuvrage(flot);

    while(!feof(flot))
    {
        tabOuvrage[*nbOuvrage] = o;
        (*nbOuvrage)++;

        aux = (Ouvrage *) realloc(tabOuvrage, (*nbOuvrage + 1) * sizeof(Ouvrage));

        if(aux == NULL)
        {
            printf("Erreur realloc. \n");
            exit(1);
        }

        tabOuvrage = aux;

        o = lireOuvrage(flot);
    }


    return tabOuvrage;
}

/*
* Fonction pour lire un ouvrage à partir d'un fichier
*/

Ouvrage lireOuvrage(FILE *flot)
{
    Ouvrage o;

    // Lecture de la cote du livre

    fscanf(flot, "%s%*c", o.cote);

    // Lecture du titre du livre

    fgets(o.titre, 50, flot);
    o.titre[strlen(o.titre) - 1] = '\0';

    // Lecture de la categorie

    fscanf(flot, "%s%*c", o.categorie);

    // Lecture de l'auteur

    fgets(o.auteur, 50, flot);
	o.auteur[strlen(o.auteur) - 1] = '\0';

	o.estEmprunte = faux;
	o.numLecteur = 0;

    return o;
}

/*
* Fonction du menu
*/

void afficherMenu(void)
{
	printf("\n========= Menu Principal =========\n");
	printf("0. Quitter\n");
	printf("1. Ajouter un lecteur.\n");
	printf("2. Afficher les lecteurs.\n");
	printf("3. Ajouter un ouvrage.\n");
	printf("4. Afficher les ouvrages.\n");
	printf("5. Afficher un lecteur.\n");
	printf("6. Supprimer un lecteur.\n");
	printf("7. Afficher un ouvrage.\n");
	printf("8. Supprimer un ouvrage.\n");
	printf("9. Modifier une adresse.\n");
	printf("10. Ajouter un emprunt.\n");
	printf("11. Retourner un emprunt.\n");
	printf("12. Afficher les emprunts retournés.\n");
	printf("=================================\n");
}

/*
* Fonction globale
*/

void global(void)
{
    FILE *fichierLecteur, *fichierOuvrage, *fichierEmpruntRetourne;

    Lecteur *tabLecteur;
    Ouvrage *tabOuvrage;
    EmpruntRetourne *tabEmpruntRetourne;

    int nbLecteur = 0, nbOuvrage = 0, nbEmpruntRetourne = 0, choix, i, j;

    // Ouverture du fichier des ouvrages

    fichierOuvrage = fopen("ouvrages.don", "r");

    if(fichierOuvrage == NULL)
    {
        printf("[ERREUR] Probleme d'ouverture du fichier des ouvrages.\n");
        exit(1);
    }

    // Lecture du fichier des ouvrages dans un tableau

    tabOuvrage = lireOuvrages(fichierOuvrage, &nbOuvrage);

    // Fermeture du fichier des ouvrages

    fclose(fichierOuvrage);

    // Ouverture du fichier des lecteurs

    fichierLecteur = fopen("lecteurs.don", "r");

    if(fichierLecteur == NULL)
    {
        printf("Erreur d'ouverture du fichier des lecteurs.\n");
        exit(1);
    }

    // Lecture du fichier des lecteurs dans un tableau

    tabLecteur = lireLecteurs(fichierLecteur, &nbLecteur, tabOuvrage, nbOuvrage);

    // Fermeture du fichier des lecteurs

    fclose(fichierLecteur);

    // Ouverture du fichier des emprunts retournés

    fichierEmpruntRetourne = fopen("empruntsretournes.don", "r");

    if(fichierEmpruntRetourne == NULL)
    {
		printf("[ERREUR] Probleme d'ouverture du fichier des emprunts retournés.\n");
        exit(1);
	}

	// Lecture du fichier des emprunts retournés dans un tableau

	tabEmpruntRetourne = lireEmpruntsRetournes(fichierEmpruntRetourne, &nbEmpruntRetourne);

	// Fermeture du fichier des emprunts retournés

	fclose(fichierEmpruntRetourne);

	// Afficher le tableau des emprunts retournés

	// afficherEmpruntsRetournes(tabEmpruntRetourne, nbEmpruntRetourne);

	while(1)
	{
		afficherMenu();

		scanf("%d", &choix);

		if(choix == 0)
			// Quitter le menu
			break;
		else if(choix == 1)
			// Ajouter un lecteur
			ajouterLecteur(tabLecteur, &nbLecteur);
		else if(choix == 2)
			// Afficher les lecteurs
			afficherLecteurs(tabLecteur, nbLecteur);
		else if(choix == 3)
			// Ajouter un ouvrage
			ajouterOuvrage(tabOuvrage, &nbOuvrage);
		else if(choix == 4)
			// Afficher les ouvrages
			afficherOuvrages(tabOuvrage, nbOuvrage);
		else if(choix == 5)
			// Afficher un lecteur
			afficherLecteur2(tabLecteur, nbLecteur);
		else if(choix == 6)
			// Supprimer un lecteur
			supprimerLecteur(tabLecteur, &nbLecteur);
		else if(choix == 7)
			// Afficher un ouvrage
			afficherOuvrage2(tabOuvrage, nbOuvrage);
		else if(choix == 8)
			// Supprimer un ouvrage
			supprimerOuvrage(tabOuvrage, &nbOuvrage);
		else if(choix == 9)
			// Modifier une adresse
			modifierAdresse(tabLecteur, nbLecteur);
		else if(choix == 10)
			// Ajouter un emprunt
			ajouterEmprunt(tabLecteur, nbLecteur, tabOuvrage, nbOuvrage);
		else if(choix == 11)
			// Retourne un emprunt
			retournerEmprunt(tabLecteur, nbLecteur, tabOuvrage, nbOuvrage, tabEmpruntRetourne, &nbEmpruntRetourne);
		else if(choix == 12)
			// Afficher les emprunts retournés
			afficherEmpruntsRetournes(tabEmpruntRetourne, nbEmpruntRetourne);
		else
			// Choix invalide
			printf("Choix invalide.\n");
	}

	// Enregister le tableau des ouvrages

	fichierOuvrage = fopen("ouvrages.don", "w");

	if(fichierOuvrage == NULL)
	{
		printf("[ERREUR] Probleme d'ouverture du fichier des ouvrages.\n");
		exit(1);
	}

	for(i = 0; i < nbOuvrage; i++)
		fprintf(fichierOuvrage, "%s\n%s\n%s\n%s\n", tabOuvrage[i].cote, tabOuvrage[i].titre, tabOuvrage[i].categorie, tabOuvrage[i].auteur);

	fclose(fichierOuvrage);

	// Enregister le tableau des lecteurs

	fichierLecteur = fopen("lecteurs.don", "w");

	if(fichierLecteur == NULL)
	{
		printf("[ERREUR] Probleme d'ouverture du fichier des lecteurs.\n");
		exit(1);
	}

	for(i = 0; i < nbLecteur; i++)
	{
		fprintf(fichierLecteur, "%d\n%s\n%s", tabLecteur[i].numero, tabLecteur[i].nom, tabLecteur[i].prenom);
		fprintf(fichierLecteur, "%d\n%s\n%d\n%s\n", tabLecteur[i].adresse.numero, tabLecteur[i].adresse.rue, tabLecteur[i].adresse.codepostal, tabLecteur[i].adresse.ville);
		fprintf(fichierLecteur, "%d\n", tabLecteur[i].nbemprunts);

		for(j = 0; j < tabLecteur[i].nbemprunts; j++)
			fprintf(fichierLecteur, "%s %d/%d/%d\n", tabLecteur[i].emprunts[j].cote, tabLecteur[i].emprunts[j].dateemprunt.jour, tabLecteur[i].emprunts[j].dateemprunt.mois, tabLecteur[i].emprunts[j].dateemprunt.annee);
	}

	fclose(fichierLecteur);

	// Enregister le tableau des emprunts retournés

	fichierEmpruntRetourne = fopen("empruntsretournes.don", "w");

	if(fichierEmpruntRetourne == NULL)
	{
		printf("[ERREUR] Probleme d'ouverture du fichier des emprunts retournés.\n");
		exit(1);
	}

	for(i = 0; i < nbEmpruntRetourne; i++)
	{
		fprintf(fichierEmpruntRetourne, "%d %s ", tabEmpruntRetourne[i].numlecteur, tabEmpruntRetourne[i].cote);
		fprintf(fichierEmpruntRetourne, "%d/%d/%d ", tabEmpruntRetourne[i].dateemprunt.jour, tabEmpruntRetourne[i].dateemprunt.mois, tabEmpruntRetourne[i].dateemprunt.annee);
		fprintf(fichierEmpruntRetourne, "%d/%d/%d\n", tabEmpruntRetourne[i].dateretour.jour, tabEmpruntRetourne[i].dateretour.mois, tabEmpruntRetourne[i].dateretour.annee);
	}

	fclose(fichierEmpruntRetourne);

	exit(0);
}

/*
 * Fonction pour ajouter un lecteur dans le tableau des lecteurs
 */

void ajouterLecteur(Lecteur *tabLecteur, int *nbLecteur)
{
	Lecteur l, *aux;

	l = saisirLecteur();

	// On regarde si le numero de lecteur n'existe pas déjà

	if(rechercheLecteur(tabLecteur, *nbLecteur, l.numero) != -1)
	{
		printf("Un lecteur existe déjà avec ce numero.\n");
		return;
	}

	// On ajoute le lecteur au tableau

	aux = (Lecteur *) realloc(tabLecteur, (*nbLecteur + 1) * sizeof(Lecteur));

	if(aux == NULL)
	{
		printf("Erreur realloc. \n");
		exit(1);
	}

	tabLecteur = aux;

	tabLecteur[*nbLecteur] = l;

	(*nbLecteur)++;

	printf("Lecteur ajouté.\n");
}

/*
 * Fonction pour rechercher un lecteur dans le tableau des lecteurs
 */

int rechercheLecteur(Lecteur *tabLecteur, int nbLecteur, int numLecteur)
{
	int i;

	for(i = 0; i < nbLecteur; i++)
		if(tabLecteur[i].numero == numLecteur)
			return i;

	return -1;
}

/*
 * Fonction pour afficher un lecteur designé par son numero de lecteur
 */

void afficherLecteur2(Lecteur *tabLecteur, int nbLecteur)
{
	int numLecteur, i;

	printf("Numero du lecteur: ");
	scanf("%d", &numLecteur);

	i = rechercheLecteur(tabLecteur, nbLecteur, numLecteur);

	if(i == -1)
	{
		printf("Numero du lecteur incorrect.\n");
		return;
	}

	afficherLecteur(tabLecteur[i]);
}

/*
 * Fonction pour modifier l'adresse d'un lecteur designé par son numero de lecteur
 */

void modifierAdresse(Lecteur *tabLecteur, int nbLecteur)
{
	int numLecteur, i, j;
	Adresse a;

	printf("Numero du lecteur: ");
	scanf("%d", &numLecteur);

	i = rechercheLecteur(tabLecteur, nbLecteur, numLecteur);

	if(i == -1)
	{
		printf("Numero du lecteur incorrect.\n");
		return;
	}

	printf("Adresse actuelle :\n");

	afficherAdresse(tabLecteur[i].adresse);

	printf("\nNouvelle adresse :\n");

	a = saisirAdresse();

	tabLecteur[i].adresse = a;

	printf("[SUCCESS] Adresse changé.\n");
}

/*
 * Fonction pour ajouter un emprunt à un lecteur
 */

void ajouterEmprunt(Lecteur *tabLecteur, int nbLecteur, Ouvrage *tabOuvrage, int nbOuvrage)
{
	int numLecteur, i, j;
	Adresse a;
	Emprunt e, *aux;

	printf("Numero du lecteur: ");
	scanf("%d", &numLecteur);

	// Verification du numero du lecteur

	i = rechercheLecteur(tabLecteur, nbLecteur, numLecteur);

	if(i == -1)
	{
		printf("[ERREUR] Numero du lecteur incorrect.\n");
		return;
	}

	// Verification du nombre d'emprunts du lecteur

	if(tabLecteur[i].nbemprunts == 3)
	{
		printf("[ERREUR] Le lecteur a atteint la limite de 3 emprunts.\n");
		return;
	}

	// Saisie de la cote

	printf("Cote: ");
	scanf("%s%*c", &e.cote);

	// Verification de la cote

	j = rechercheOuvrage(tabOuvrage, nbOuvrage, e.cote);

	if(j == -1)
	{
		printf("[ERREUR] Cote du livre incorrect.\n");
		return;
	}

	// Saisie de la date d'emprunt

	printf("Date d'emprunt:\n");
	e.dateemprunt = saisirDate();

	// On augmente la taille du tableau des emprunts pour le lecteur

	aux = (Emprunt *) realloc(tabLecteur[i].emprunts, (tabLecteur[i].nbemprunts + 1) * sizeof(Emprunt));

	if(aux == NULL)
	{
		printf("[ERREUR] Erreur realloc.\n");
		exit(1);
	}

	tabLecteur[i].emprunts = aux;

	tabLecteur[i].emprunts[tabLecteur[i].nbemprunts] = e;

	// On incremente le nombre d'emprunts du lecteur

	tabLecteur[i].nbemprunts++;

	printf("[SUCCESS] Emprunt ajouté.\n");
}

/*
 * Fonction pour supprimer un lecteur du tableau des lecteurs
 */

void supprimerLecteur(Lecteur *tabLecteur, int *nbLecteur)
{
	int numLecteur, i, j;

	// Saisie du numero du lecteur

	printf("Numero du lecteur: ");
	scanf("%d", &numLecteur);

	// Verification du numero du livre

	i = rechercheLecteur(tabLecteur, *nbLecteur, numLecteur);

	if(i == -1)
	{
		printf("[ERREUR] Numero du lecteur incorrect.\n");
		return;
	}

	// Verification des emprunts en cours

	if(tabLecteur[i].nbemprunts != 0)
	{
		printf("[ERREUR] Suppression impossible, le lecteur a encore des emprunts.\n");
		return;
	}

	// Suppression du lecteur par decalage : tab[n] devient tab[n + 1] à partir de l'index du lecteur que l'on souhaite supprimer

	for(j = i; j < *nbLecteur - 1; j++)
	{
		tabLecteur[j] = tabLecteur[j + 1];
	}

	(*nbLecteur)--;

	printf("[SUCCES] Lecteur supprimé.");
}

/*
 * Fonction pour ajouter un ouvrage au tableau des ouvrages
 */

void ajouterOuvrage(Ouvrage *tabOuvrage, int *nbOuvrage)
{
	Ouvrage o, *aux;

	// Saisie de l'ouvrage

	o = saisirOuvrage();

	// Allocation d'un tableau d'ouvrage plus grand

	aux = (Ouvrage *) realloc(tabOuvrage, (*nbOuvrage + 1) * sizeof(Ouvrage));

	if(aux == NULL)
	{
		printf("[ERREUR] Probleme realloc.\n");
		exit(1);
	}

	tabOuvrage = aux;

	tabOuvrage[*nbOuvrage] = o;

	// Incrementation du nombre d'ouvrages

	(*nbOuvrage)++;

	printf("[SUCCES] Ouvrage ajouté.\n");
}

/*
 * Fonction pour rechercher un ouvrage dans le tableau des ouvrages par cote
 */

int rechercheOuvrage(Ouvrage *tabOuvrage, int nbOuvrage, char cote[6])
{
	int i;

	// On regarde chaque element du tableau avec la boucle

	for(i = 0; i < nbOuvrage; i++)
		if(strcmp(tabOuvrage[i].cote, cote) == 0)
			// Des que l'on trouve l'element recherché on sort du boucle et de la fonction en retournant l'indice
			return i;

	// Si on ne trouve pas l'element recherché on retourne -1
	return -1;
}

/*
 * Fonction pour afficher un ouvrage designé par la cote
 */

void afficherOuvrage2(Ouvrage *tabOuvrage, int nbOuvrage)
{
	char cote[6];
	int i;

	// Saisie de la cote du livre

	printf("Cote du livre: ");
	scanf("%s%*c", cote);

	// Verification de la cote du livre

	i = rechercheOuvrage(tabOuvrage, nbOuvrage, cote);

	if(i == -1)
	{
		printf("[ERREUR] Cote du livre incorrect.\n");
		return;
	}

	// Affichage de l'ouvrage

	afficherOuvrage(tabOuvrage[i]);
}

/*
 * Fonction pour supprimer un ouvrage designé par la cote
 */

void supprimerOuvrage(Ouvrage *tabOuvrage, int *nbOuvrage)
{
	char cote[6];
	int i, j;

	// Saisie de la cote du livre

	printf("Cote du livre: ");
	scanf("%s%*c", cote);

	// Verification de la cote du livre

	i = rechercheOuvrage(tabOuvrage, *nbOuvrage, cote);

	if(i == -1)
	{
		printf("Cote du livre incorrect.\n");
		return;
	}

	// Verification si l'ouvrage est actuellement emprunté

	if(tabOuvrage[i].estEmprunte == vrai)
	{
		printf("[ERREUR] Le livre est actuellement emprunté par le lecteur %d.\n", tabOuvrage[i].numLecteur);
		return;
	}

	// Suppression du livre par decalage : tab[n] devient tab[n + 1] à partir de l'index du livre que l'on souhaite supprimer

	for(j = i; j < *nbOuvrage - 1; j++)
	{
		tabOuvrage[j] = tabOuvrage[j + 1];
	}

	(*nbOuvrage)--;

	printf("Ouvrage supprimé.");
}

/*
 * Fonction pour rechercher un emprunt parmi le tableau des lecteurs
 */

int rechercheEmprunt(Emprunt *tabEmprunt, int nbEmprunt, char cote[6])
{
	int i;

	for(i = 0; i < nbEmprunt; i++)
		if(strcmp(tabEmprunt[i].cote, cote) == 0)
			return i;

	return -1;
}

void retournerEmprunt(Lecteur *tabLecteur, int nbLecteur, Ouvrage *tabOuvrage, int nbOuvrage, EmpruntRetourne *tabEmpruntRetourne, int *nbEmpruntRetourne)
{
	char cote[6];
	int i, j, k, l;
	EmpruntRetourne e, *aux;

	// Saisie de la cote du livre

	printf("Cote du livre: ");
	scanf("%s%*c", cote);

	// Verification de la cote du livre

	i = rechercheOuvrage(tabOuvrage, nbOuvrage, cote);

	if(i == -1)
	{
		printf("[ERREUR] Cote du livre incorrect.\n");
		return;
	}

	// Verification si l'ouvrage est actuellement emprunté

	if(tabOuvrage[i].estEmprunte == faux)
	{
		printf("[ERREUR] Le livre n'est pas emprunté actuellement.\n");
		return;
	}

	// Le livre est bien emprunter, trouvons l'indice du lecteur pour enlever l'emprunt

	j = rechercheLecteur(tabLecteur, nbLecteur, tabOuvrage[i].numLecteur);

	// Verification du numero du lecteur

	if(i == -1)
	{
		printf("[ERREUR] Le lecteur n'existe plus.\n");
		return;
	}

	k = rechercheEmprunt(tabLecteur[i].emprunts, tabLecteur[i].nbemprunts, cote);

	if(k == -1)
	{
		printf("[ERREUR] L'emprunt n'existe plus...\n");
		return;
	}

	e.numlecteur = tabLecteur[i].numero;
	strcpy(e.cote, cote);
	e.dateemprunt = tabLecteur[i].emprunts[k].dateemprunt;

	// Saisie de la date de retour

	printf("Date de retour:\n");
	e.dateretour = saisirDate();

	// Suppression de l'emprunt du lecteur

	for(l = k; l < tabLecteur[i].nbemprunts; l++)
		tabLecteur[i].emprunts[l] = tabLecteur[i].emprunts[l + 1];

	(tabLecteur[i].nbemprunts)--;

	// Ajout de l'emprunt retourné au tableau des emprunts retournés

	aux = (EmpruntRetourne *) realloc(tabEmpruntRetourne, (*nbEmpruntRetourne + 1) * sizeof(EmpruntRetourne));

	if(aux == NULL)
	{
		printf("[ERREUR] Probleme realloc.\n");
		exit(1);
	}

	tabEmpruntRetourne = aux;

	tabEmpruntRetourne[*nbEmpruntRetourne] = e;

	(*nbEmpruntRetourne)++;

	printf("[SUCCES] Emprunt retourné.\n");
}










