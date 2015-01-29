#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int jour;
	int mois;
	int annee;
} Date;

typedef struct {
	int numero;
	char rue[50];
	int codepostal;
	char ville[20];
} Adresse;

typedef struct {
	char cote[6];
	Date dateemprunt;
} Emprunt; 

typedef struct {
	int numero;
	char nom[20];
	char prenom[20];
	Adresse adresse;
	int nbemprunts;
	Emprunt *emprunts;
} Lecteur;

typedef enum {
	faux, vrai
} Booleen;

typedef struct {
	char cote[6];
	char titre[50];
	char categorie[6];
	char auteur[50];
	Booleen estEmprunte;
	int numLecteur;
} Ouvrage;

typedef struct {
	int numlecteur;
	char cote[6];
	Date dateemprunt;
	Date dateretour;
} EmpruntRetourne;


Lecteur saisirLecteur(void);
Ouvrage saisirOuvrage(void);
Adresse saisirAdresse(void);
Date saisirDate(void);

void afficherLecteurs(Lecteur *tabLecteur, int nbLecteur);
void afficherLecteur(Lecteur l);

void afficherAdresse(Adresse a);

void afficherEmprunts(Emprunt *tabEmprunt, int nbEmprunt);
void afficherEmprunt(Emprunt e);

void afficherEmpruntsRetournes(EmpruntRetourne *tabEmpruntRetourne, int nbEmpruntRetourne);
void afficherEmpruntRetourne(EmpruntRetourne e);

void afficherDate(Date d);

void afficherOuvrages(Ouvrage *tabOuvrage, int nbOuvrage);
void afficherOuvrage(Ouvrage o);

Lecteur * lireLecteurs(FILE *flot, int *nbLecteur, Ouvrage *tabOuvrage, int nbOuvrage);
Lecteur lireLecteur(FILE *flot, Ouvrage *tabOuvrage, int nbOuvrage);

Adresse lireAdresse(FILE *flot);

Emprunt * lireEmprunts(FILE *flot, int nbEmprunt, Ouvrage *tabOuvrage, int nbOuvrage, int numLecteur);
Emprunt lireEmprunt(FILE *flot, Ouvrage *tabOuvrage, int nbOuvrage, int numLecteur);

EmpruntRetourne * lireEmpruntsRetournes(FILE *flot, int *nbEmpruntRetourne);
EmpruntRetourne lireEmpruntRetourne(FILE *flot);

Date lireDate(FILE *flot);

Ouvrage * lireOuvrages(FILE *flot, int *nbOuvrage);
Ouvrage lireOuvrage(FILE *flot);

void menu(void);

void ajouterLecteur(Lecteur *tabLecteur, int *nbLecteur);
int rechercheLecteur(Lecteur *tabLecteur, int nbLecteur, int numLecteur);
void afficherLecteur2(Lecteur *tabLecteur, int nbLecteur);
void modifierAdresse(Lecteur *tabLecteur, int nbLecteur);
void ajouterEmprunt(Lecteur *tabLecteur, int nbLecteur, Ouvrage *tabOuvrage, int nbOuvrage);
void supprimerLecteur(Lecteur *tabLecteur, int *nbLecteur);

void ajouterOuvrage(Ouvrage *tabOuvrage, int *nbOuvrage);
int rechercheOuvrage(Ouvrage *tabOuvrage, int nbOuvrage, char cote[5]);
void afficherOuvrage2(Ouvrage *tabOuvrage, int nbOuvrage);
void supprimerOuvrage(Ouvrage *tabOuvrage, int *nbOuvrage);

int rechercheEmprunt(Emprunt *tabEmprunt, int nbEmprunt, char cote[6]);
void retournerEmprunt(Lecteur *tabLecteur, int nbLecteur, Ouvrage *tabOuvrage, int nbOuvrage, EmpruntRetourne *tabEmpruntRetourne, int *nbEmpruntRetourne);
