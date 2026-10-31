
import re
import sys
import matplotlib.pyplot as plt

fichier = sys.argv[1] if len(sys.argv) > 1 else "resultats.csv"
nmax = int(sys.argv[2]) if len(sys.argv) > 2 else None

# --- Lecture du CSV (sections "les resultats en utilisant algoN") ---
data, cur = {}, None
with open(fichier, encoding="utf-8", errors="replace") as f:
    for ligne in f:
        ligne = ligne.strip()
        if not ligne:
            continue
        m = re.match(r"les resultats en utilisant algo(\d)", ligne)
        if m:
            cur = int(m.group(1))
            data[cur] = []
            continue
        m = re.search(r"N = (\d+) \| (\w+) \| ([\d.]+) secondes", ligne)
        if m:                                   # format "N = ... | ... | ... secondes"
            data[cur].append((int(m.group(1)), float(m.group(3))))
            continue
        p = ligne.split(";")
        if len(p) == 4:                         # format "fichier;n;Premier;temps"
            data[cur].append((int(p[1]), float(p[3])))

# --- Figure : échelle log (haut) + zoom linéaire (bas) ---
couleurs = ["#1f77b4", "#ff7f0e", "#2ca02c", "#d62728"]
fig, (ax1, ax2) = plt.subplots(
    2, 1, figsize=(11, 8), sharex=True,
    gridspec_kw={"height_ratios": [3, 1.1], "hspace": 0.12},
)

for k in sorted(data):
    pts = [(n, t) for n, t in data[k] if nmax is None or n <= nmax]
    x = [n for n, _ in pts]
    y = [t for _, t in pts]
    # haut : on retire les temps 0 (impossibles en échelle log)
    ax1.scatter([n for n, t in pts if t > 0], [t for _, t in pts if t > 0],
                s=14, color=couleurs[k - 1], alpha=0.75, lw=0, label=f"A{k}")
    # bas : tous les points
    ax2.scatter(x, y, s=14, color=couleurs[k - 1], alpha=0.75, lw=0, label=f"A{k}")

ax1.set_yscale("log")
ax1.set_ylabel("Temps (secondes)")
ax1.set_title(f"Nuage de points — {fichier}")
ax1.text(0.02, 0.95, "Échelle logarithmique", transform=ax1.transAxes,
         fontsize=8, va="top")
ax1.legend(title="Algorithme", loc="center", fontsize=8, title_fontsize=8)
ax1.grid(alpha=0.25)

ax2.set_ylim(0, 0.006)                 # à adapter à vos données
ax2.set_ylabel("Temps (secondes) — zoom")
ax2.set_xlabel("n")
ax2.legend(title="Algorithme", loc="upper left", fontsize=7, title_fontsize=7)
ax2.grid(alpha=0.25)

if nmax:
    ax2.set_xlim(0, nmax)              # axe n linéaire comme sur la photo
else:
    ax1.set_xscale("log")              # n va jusqu'à ~1e10 : échelle log

fig.savefig("nuage_points.png", dpi=150, bbox_inches="tight")
plt.show()
