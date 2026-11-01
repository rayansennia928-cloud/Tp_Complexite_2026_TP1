
import pandas as pd
import matplotlib.pyplot as plt

# Fichiers des 4 algorithmes
fichiers = {
    "Algo 1": "../tableaux/resultats_A1.csv",
    "Algo 2": "../tableaux/resultats_A2.csv",
    "Algo 3": "../tableaux/resultats_A3.csv",
    "Algo 4": "../tableaux/resultats_A4.csv"
}

fig, (ax1, ax2) = plt.subplots(
    2, 1,
    figsize=(12, 7),
    sharex=True,
    gridspec_kw={"height_ratios": [2, 1]}
)

marqueurs = ["o", "s", "^", "D"]

for i, (nom_algo, fichier) in enumerate(fichiers.items()):

    df = pd.read_csv(fichier, sep=";")

    # Garder uniquement Test-1
    test1 = df[
        df["Fichier"].str.lower().str.contains("test-1")
    ].copy()

    # Nettoyage des données
    test1["Nombre"] = pd.to_numeric(
        test1["Nombre"], errors="coerce"
    )

    test1["Temps_secondes"] = pd.to_numeric(
        test1["Temps_secondes"].astype(str)
        .str.replace(" secondes", "", regex=False)
        .str.strip(),
        errors="coerce"
    )

    test1 = test1.dropna(
        subset=["Nombre", "Temps_secondes"]
    )

    # Graphique supérieur : échelle logarithmique
    positif = test1[
        (test1["Nombre"] > 0) &
        (test1["Temps_secondes"] > 0)
    ]

    ax1.scatter(
        positif["Nombre"],
        positif["Temps_secondes"],
        label=nom_algo,
          marker="o",
        s=20,
        alpha=0.8
    )

    # Graphique inférieur : zoom linéaire
    ax2.scatter(
        test1["Nombre"],
        test1["Temps_secondes"],
        label=nom_algo,
        marker="o",
        s=25,
        alpha=0.8
    )

# Configuration du graphique supérieur
ax1.set_xscale("log")
ax1.set_yscale("log")
ax1.set_ylabel("Temps (secondes)")
ax1.set_title("Nuage de points — Test-1")
ax1.text(
    0.02, 0.93,
    "Echelle logarithmique",
    transform=ax1.transAxes,
    fontsize=9
)
ax1.legend(title="Algorithme")
ax1.grid(True, alpha=0.3, which="both")

# Configuration du zoom inférieur
ax2.set_xscale("log")
ax2.set_ylim(0, 0.0065)
ax2.set_xlabel("Nombre testé (n)")
ax2.set_ylabel("Temps (secondes) → zoom")
ax2.legend(title="Algorithme")
ax2.grid(True, alpha=0.3)

# Espacement et sauvegarde
plt.tight_layout()

plt.savefig(
    "Figure_test1.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()
