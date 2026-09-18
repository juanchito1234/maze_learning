# qlearning-maze

Librería en C que implementa un agente de **Q-learning** que aprende a resolver
un laberinto por su cuenta, a base de prueba y error.

Proyecto para practicar C (structs, punteros, memoria dinámica, E/S de
archivos) mientras se aprenden los fundamentos del aprendizaje por refuerzo.

## Estructura del proyecto

```
qlearning-maze/
├── Makefile          # Cómo compilar el proyecto
├── README.md         # Este archivo
├── .gitignore
├── include/          # Headers (.h) — QUÉ hace cada módulo
│   ├── env.h         # El entorno: el laberinto
│   ├── agent.h       # El agente: tabla Q y política
│   └── utils.h       # Utilidades varias (random, impresión, etc.)
├── src/              # Implementación (.c) — CÓMO lo hace cada módulo
│   ├── main.c        # Punto de entrada del programa
│   ├── env.c
│   ├── agent.c
│   └── utils.c
├── data/             # Acá se va a guardar el modelo entrenado (tabla Q)
├── obj/              # Archivos objeto (.o) generados al compilar (no se versiona)
└── bin/              # Ejecutable final (no se versiona)
```

## Por qué está separado así

- **`include/` vs `src/`**: es la convención estándar en C. El `.h` dice
  "qué funciones/tipos existen" (la interfaz), el `.c` dice "cómo están
  hechas por dentro" (la implementación). Así, otros archivos pueden usar
  `env.h` sin necesitar saber cómo está implementado `env.c`.
- **Un módulo por responsabilidad**: `env` (el mundo), `agent` (el cerebro),
  `utils` (herramientas compartidas). Esto evita un único archivo gigante
  y hace más fácil razonar sobre cada parte por separado.
- **`data/`**: separar los datos generados (la tabla Q entrenada) del código
  fuente.

## Cómo compilar

```bash
make        # compila -> genera bin/qlearning
make run    # compila y ejecuta
make clean  # borra obj/ y bin/
```

Por ahora `main.c` solo imprime un mensaje confirmando que todo compila:
el resto de los archivos están vacíos a propósito, listos para que los
vayamos completando paso a paso.
