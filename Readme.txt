
|===========================================================|
|================= PROJET LIFAP4 imagiNABle ================|
|===========================================================|




Notes du groupe : 
   Un affichage en plein écran est conseillé pour une lecture plus agréable du fichier readme.txt.
   Jeu jouable sous Linux, Windows.




#===========================================================#
             Informations factuelles du projet :
=============================================================

ÉTUDIANTS :
   BRIGUET Benoît p1915036
   LETO Aymeric p1907585
   PURICELLI Nathan p1907453

PROJET SUR LA FORGE DE LYON1 :
   Nom : CurveFever
   Project ID : 18519
   Créateur : PURICELLI Nathan p1907453

#===========================================================#




#===========================================================#
		  MANUEL D'UTILISATION : 
=============================================================



#===========================================================#
               Comment compiler et exécuter : 
=============================================================

Avant de compiler : 
   Il faut installer les librairies de sdl.
   Sous windows : Il faut disposer de la fonction make dans les variables d'environnement
   Sous Linux : effectuer la commande : sudo apt install  libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev

Pour compiler :
   Sur la console, se mettre dans le répertoire racine (il contient le makefile).
   Sous Linux et macOS : 
      effectuer les commandes :	$> make veryclean
					                  $> make 
   Sous windows :
      effectuer les commandes :  $> make veryclean -f Makefile2
					                  $> make -f Makefile2
					
=============================================================

Pour exécuter :
   Sur la console, se mettre dans le répertoire racine,
   puis faire la commande : $> ./bin/nom_de_lexecutable

					$> ./bin/curvefever_txt	---> Pour lancer une version .txt du jeu.
					$> ./bin/		---> Pour lancer la version graphique du jeu (utilisant SDL).

=============================================================



#===========================================================#
      Règles du jeu et utilisation de l'application : 
=============================================================

Les règles :

   L'application imagiNABle reprend le jeu de serpents "Curve Fever" où chaque joueur doit éviter le plus longtemps possible de rentrer dans sa propre trace et celle de son adversaire sur un plateau de jeu.
   Les "traces" des joueurs sont marquées sur le terrain aux endroits où les serpents passent tout au long de la partie.
   Lorsqu’une des deux “têtes” entre en contact avec une trace, le joueur la controllant perd la partie qui se termine alors.

=============================================================

Utilisation de l'application :

   Pour utiliser l'application imagiNABle (en version graphique, c'est plus sympa), il faut tout d'abord compiler le programme et ensuite l'exécuter (cf. Comment compiler et exécuter).
   Vous entrez ainsi dans l'interface de jeu.
   ***
    ---> Le joueur 1 se déplace avec les touches Q et D du clavier.
    ---> Le joueur 2 se déplace avec les touches K et M du clavier.
   ***
   Pour fermer l'application il suffit de ***.


=============================================================



#===========================================================#
          Liste des fonctionnalités du programme : 
=============================================================

Voici une liste des fonctionnalités de l’application imagiNABle :

   -> Jeu à 2 joueurs en local.
   -> Départ simultané et déplacement des têtes des 2 joueurs + contrôle de leur direction via le clavier (cf. Utilisation de l'application).
   -> La trace des joueurs est marquée sur le terrain de jeu et laisse parfois des trous.
   -> Le contact entre la tête d’un joueur et les traces ou les délimitations du terrain entraîne la défaite du joueur.


#===========================================================#






#===========================================================#
                ORGANISATION DE L'ARCHIVE :
=============================================================

Le répertoire principal contient les sous-répertoires bin, src, obj, data et doc.


   -> /bin : contient les executables.

   -> /dep : contient des fichiers de dépendances pour la compilation après avoir compilé.

   -> /src : contient les fichiers sources (.h et .cpp) du projet, et plus globalement tout le code de l'application.

   -> /obj : contient les fichiers .o (fichiers objets) de tous les fichiers .cpp pour exécuter.

   -> /data : contient les assets de notre application.

   -> /doc : contient la présentation orale du projet, le diagramme des classes UML final du projet, le diagramme de Gantt final du projet avec une description de ce qui a été fait.
	     contient la partie documentation Doxygen avec : curvefever.doxy qui est le fichier de configuration de doxygen.
             						  html/index.html qui est la page d'entrée de la documentation (générée avec doxygen).

=============================================================

Le répertoire principal contient le fichier Makefile.

=============================================================

Le répertoire principal contient un fichier Readme.txt (celui-ci !), un fichier texte contenant

   -> des informations factuelles.
   -> un manuel d'utilisation.
   -> l'organisation de l'archive.

#===========================================================#


|===========================================================|
|============= PROJET LIFAP4 imagiNABle (FIN) ==============|
|===========================================================|
