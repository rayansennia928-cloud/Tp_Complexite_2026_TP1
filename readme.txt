nous avons mené une étude comparative sur les performances de quatre algorithmes distincts, notés A1, A2, A3 et A4. L'objectif principal de ce travail est d'évaluer leur complexité temporelle et leur stabilité face à des volumes de données croissants. Ce rapport détaille la méthodologie employée, les jeux de données utilisés, ainsi qu'une analyse approfondie des résultats obtenus à travers des représentations graphiques.
Afin d'évaluer les performances des quatre algorithmes A1, A2, A3 et A4, nous avons utilisé trois jeux de données présentant des caractéristiques différentes :
- Test-1 : Échantillon de nombres premiers
Cet échantillon contient 100 nombres premiers sélectionnés dans l'intervalle [1 000, 1 000 000]. Il permet d'évaluer le comportement des algorithmes sur des nombres premiers de différentes tailles, appartenant au même intervalle numérique.
- Test-2 : Échantillon contrôlé selon le nombre de chiffres
Ce jeu de données est constitué d'échantillons contrôlés en fonction du nombre de chiffres des nombres testés. Par exemple, il contient 10 nombres à 3 chiffres. Cette organisation permet d'étudier l'évolution des performances en fonction de la taille des nombres.
- Test-3 : Échantillon structuré selon le nombre de chiffres
Ce jeu de données contient des nombres organisés en différentes catégories selon leur nombre de chiffres : 3, 6, 9 et 12 chiffres. Il permet de comparer les performances des algorithmes face à des nombres de tailles numériques très différentes et d'observer l'influence de cette taille sur le temps d'exécution.
Les algorithmes ont été exécutés sur les jeux de données décrits ci-dessus. Les temps d'exécution (en secondes) ont été mesurés pour différentes tailles d'entrée (notées n). Les résultats sont présentés sous forme de nuages de points. Pour faciliter la lecture, une échelle logarithmique a été utilisée sur l'axe des ordonnées (temps) et/ou des abscisses (n). Un zoom sur les temps d'exécution les plus faibles a également été intégré pour distinguer les algorithmes les plus rapides.
L'analyse visuelle des graphiques générés (Random1000, Test-1, resultats.csv) permet de dégager des tendances claires quant au comportement des quatre algorithmes.
Les algorithmes A1 et A2 se distinguent immédiatement par des temps d'exécution nettement plus élevés que les deux autres.
- Tendance : Sur les graphiques en échelle logarithmique (ex: Figure 1 et Figure 2), on observe une croissance quasi-linéaire (en log-log) du temps en fonction de n. Cela suggère une complexité polynomiale (probablement O(n) ou O(nlog⁡n)). Pour des valeurs de n atteignant 1010, le temps d'exécution dépasse la centaine de secondes.
- Comparaison : A1 et A2 semblent avoir des performances très proches. Cependant, sur les grandes valeurs de n, A1 montre une dispersion verticale plus importante, indiquant une légère instabilité ou des temps légèrement supérieurs à A2 dans certains cas.
- Cas spécifique (Test-1) : Sur le jeu de données "Test-1" (Figure 3), l'algorithme A1 est le seul à montrer une activité significative, avec des temps grimpant jusqu'à 6×10−3 secondes, tandis que A2 reste confondu avec l'axe des abscisses. Cela suggère que A1 est plus sensible à la nature des nombres (ici, les nombres premiers) que A2.
Les algorithmes A3 et A4 affichent des performances radicalement différentes.
- Performance : Sur le graphique "Random1000" (Figure 1), leurs temps restent extrêmement faibles, de l'ordre de 10−3 à 10−2 secondes, même pour des tailles d'entrée très importantes (n=1010). Ils sont "écrasés" par l'échelle utilisée pour visualiser A1 et A2.
- Stabilité : Le zoom (partie inférieure des figures) révèle que A4 est l'algorithme le plus rapide et le plus stable. A3 montre quelques pics de latence sporadiques (par exemple vers n=109 sur la Figure 1), probablement dus à des effets systèmes ou à des cas particuliers dans les données.
- Conclusion sur ce groupe : A4 semble être l'algorithme le plus efficace en termes de temps de calcul pur, avec une complexité qui semble tendre vers une constante ou une fonction très sous-linéaire (comme O(log⁡n)).
Le tableau ci-dessous résume nos observations :



Ce travail de comparaison nous a permis de mettre en évidence des disparités majeures de performance entre les quatre algorithmes.

Les algorithmes A1 et A2 présentent une complexité temporelle pénalisante pour les grandes entrées, avec des temps d'exécution qui augmentent de manière significative avec n. Leur utilisation n'est pas recommandée pour des applications nécessitant un traitement rapide sur de grands volumes de données.

À l'inverse, les algorithmes A3 et A4 surclassent largement leurs homologues. L'algorithme A4 s'impose comme la solution la plus performante et la plus stable de notre étude, avec des temps d'exécution restant constamment proches de zéro, ce qui en fait un excellent candidat pour des applications à grande échelle.

En perspective, il serait intéressant d'analyser la consommation mémoire de ces algorithmes pour compléter cette étude de complexité et d'identifier les raisons structurelles (structures de données utilisées, boucles, etc.) expliquant la supériorité de A4 sur A3.