# Gomoku

Play [Gomoku](https://en.wikipedia.org/wiki/Gomoku) versus another human or Artificial Intelligence.

Implemented various Artificial Intelligence strategies:
* Minimax
* Minimax + Alpha-beta pruning
* Monte Carlo Tree Search

Coming soon:
* Neural Networks

**How to play**

Downlaod source code:
```
git clone https://github.com/pawel-kieliszczyk/gomoku.git
```

Compile:
```
cd gomoku
bazel build source:app
```

Play:
```
./bazel-bin/source/app
```
