# 📋 Changelog — `frfaria`

> Registro de cambios, reorganización y progreso de la rama.

---

## 🏷️ Tipos de cambios

| Etiqueta | Significado |
|---|---|
| 🟢 **Añadido** | Nueva funcionalidad |
| 🔵 **Modificado** | Cambios en funcionalidad existente |
| 🟡 **Reorganizado** | Renombrado, reordenación o movimiento de archivos |
| 🟣 **Corregido** | Corrección de errores |
| ⚪ **Otros** | Cambios menores, estilo, etc. |

---

## 📅 Historial

### `27/11/2026` · `18:48`
**Commit:** `changed operator return type`

- 🟢 Se cambió el tipo de retorno de todos los operadores de Push_swap de `void` a `size_t`.

### `27/11/2026` · `00:35`
**Commit:** `Implement and validate Turk Sort`

- 🟢 Implementación completa del algoritmo Turk Sort para ordenar los elementos de A utilizando B como stack auxiliar.
- 🔵 Implementación del cálculo de costes para encontrar la inserción más eficiente, aprovechando rotaciones simultáneas (`rr` y `rrr`).
- 🟡 Implementación de la rotación final para dejar el menor índice en la cima de A.
- ⚪ Validación con 1.000 números aleatorios mediante `checker_linux`: resultado `OK`, con 14.047 operaciones.

### `24/11/2026` · `02:16`
**Commit:** `advances on simple`

- 🔵 Se cambia el tipo de `t_cost.total` de `int` a `size_t`.
- 🟢 Se implementa `ft_sort3()` para ordenar los tres elementos restantes de A.
- 🟢 Se añade `find_target()` para encontrar el objetivo de inserción de cada nodo de B en A.
- 🟢 Se añade `no_target()` para localizar el nodo de menor índice cuando no existe un objetivo de inserción válido.
- 🟢 Se comienza a implementar `ft_price()` y `ft_find_cheapest()` para calcular los costes de movimiento y seleccionar el movimiento más barato. (WIP)

### `23/11/2026` · `20:54`
**Commit:** `algoritmo simple (wip)`

- 🟢 Se añade la estructura `t_cost` para almacenar los costes de movimientos del algoritmo simple.
- 🔵 Se comienza a implementar el algoritmo simple, incluyendo el cálculo de precios y la búsqueda del movimiento más barato. (WIP)

### `22/11/2026` · `19:38`
**Commit:** `separate index assign into its own function`

- 🟢 Added `ft_assign_index()` to assign each node an index based on its value's rank in the stack.
- 🔵 Added the `index` field to `t_node`.
- 🟣 Updated the Makefile to compile and include `ft_assign_index.c`.
- 🟢 Tested index assignment with stacks containing 1, 2, and 100 values.

### `21/11/2026` · `20:47`
**Commit:** `compacted print stacks`

- 🔵 Simplificación de `print_stacks`, gran reduccion del tamaño.

### `21/11/2026` · `20:34`
**Commit:** `print stacks added`

- 🟢 Se añadió una función para imprimir el contenido de ambos stacks.
- 🟡 Se añadió su declaración en un apartado propio del header y se incorporó el archivo al Makefile.

### `21/11/2026` · `19:12`
**Commit:** `makefile and declaration fixes`

- 🟣 Se corrigieron las declaraciones de estructuras, sustituyendo `t_list` por `t_node` donde correspondía.
- 🟢 Makefile creado pero incompleto.

### `21/11/2026` · `16:06`
**Commit:** `list declaration fix`

- 🟣 Renombrada la estructura propia de `t_list` a `t_node` para evitar conflictos con la definición de `t_list` de Libft.

### `21/11/2026` · `16:30`
**Commit:** `header fixed`

- 🟣 Corregido el header.
- 🟡 Renombrados y reorganizados algunos archivos.

---

<!-- TEMPLATE FOR FUTURE ENTRIES

### `dd/mm/aaaa` · `hh:mm`
**Commit:** `commit name`

- 🟢 Descripción del cambio.
- 🔵 Descripción del cambio.
- 🟡 Descripción del cambio.
- 🟣 Descripción del cambio.

-->

---

## 🚧 Próximos pasos

- [ ] Implementacion de algoritmo simple.
- [ ] Implementacion de algoritmo complejo.
