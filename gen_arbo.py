# -*- coding: utf-8 -*-
import os
import json

def get_tree(path):
    tree = {"name": os.path.basename(path), "children": []}
    if os.path.isdir(path):
        for entry in os.listdir(path):
            if entry.startswith('.'):  # Ignore les fichiers et dossiers cachés
                continue
            child_path = os.path.join(path, entry)
            tree["children"].append(get_tree(child_path))
    return tree

def main():
    path = "."  # Remplacez par le chemin du dossier 42LiteBash
    tree = get_tree(path)
    with open("tree_data.json", "w") as f:
        json.dump(tree, f, indent=2)

if __name__ == "__main__":
    main()