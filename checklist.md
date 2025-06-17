# ✅ Push_swap – Check List de Progreso

## 📦 ESTRUCTURA INICIAL DEL PROYECTO
- [X] Crear estructura de carpetas (`src/`, `include/`, `tests/`)
- [X] Crear archivo `Makefile` funcional
- [X] Crear archivo principal `main.c`
- [X] Crear archivo de header general (`push_swap.h`)
- [X] Definir estructuras (stack, nodos, etc.)

---

## 🔍 PARSING Y VALIDACIONES
- [X] Leer argumentos de `main(int argc, char **argv)`
- [X] Manejar múltiples argumentos juntos (ej. `"1 2 3"`)
- [X] Convertir argumentos a enteros con protección contra:
  - [X] Números no válidos (letras, caracteres)
  - [X] Duplicados
  - [X] Números fuera de rango (INT_MIN / INT_MAX)
- [X] Crear pila `A` con los valores parseados

---

## 🔧 OPERACIONES DE PILAS
- [X] Implementar `sa`, `sb`, `ss` (swap)
- [X] Implementar `pa`, `pb` (push)
- [X] Implementar `ra`, `rb`, `rr` (rotate)
- [X] Implementar `rra`, `rrb`, `rrr` (reverse rotate)
- [X] Verificar que todas modifican correctamente las pilas

---

## 🧠 ALGORITMO DE ORDENAMIENTO

### Casos pequeños
- [X] Ordenar 2 números
- [X] Ordenar 3 números
- [X] Ordenar 5 números

### Casos grandes
- [ ] Implementar algoritmo para 100 números
- [ ] Implementar algoritmo para 500 números
- [ ] Minimizar el número de movimientos
- [ ] Optimizar el uso de `pb` y `pa` para reconstrucción

---

## 🧹 CONTROL DE ERRORES Y MEMORIA
- [X] Liberar memoria al salir (pilas, nodos, etc.)
- [X] Manejar errores con mensajes claros
- [X] Pasar `valgrind` sin leaks ni errores

---

## 📈 TESTING Y OPTIMIZACIÓN
- [ ] Crear script para generar inputs aleatorios
- [ ] Medir número de instrucciones para 100 / 500 elementos
- [ ] Comparar contra benchmarks del subject
- [ ] Mejorar estrategias si exceden los límites

---

## 🚀 ENTREGA FINAL
- [ ] Pasar norminette sin errores
- [ ] Tests básicos y pruebas manuales realizadas
- [ ] Última revisión del código

