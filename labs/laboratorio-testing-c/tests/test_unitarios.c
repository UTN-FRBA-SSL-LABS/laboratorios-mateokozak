#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/* ═══════════════════════════════════════════════════════════════════════════
 *  TESTS ESCRITOS — ya funcionan, son el punto de partida
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_carrito_nuevo(void) {
    printf("\n[carrito nuevo]\n");
    Carrito c;
    carrito_init(&c);
    ASSERT_IGUAL(0, carrito_contar(&c));
}

void test_agregar_uno(void) {
    printf("\n[agregar un producto]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    ASSERT_IGUAL(1, carrito_agregar(&c, p));   /* devuelve 1 = exito */
    ASSERT_IGUAL(1, carrito_contar(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE A — Agregar el siguiente test (ver README.md, Parte 4)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: pegar aqui la funcion test_total_precio_unitario() */
void test_total_precio_unitario(void) {
    printf("\n[total: un producto, cantidad 1]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    ASSERT_IGUAL(350, carrito_total(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE B — Completar los blancos (ver README.md, Parte 5)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: pegar y completar la funcion test_total_con_cantidad() */
void test_total_con_cantidad(void) {
    printf("\n[total: un producto, cantidad 2]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, p);
    ASSERT_IGUAL(700, carrito_total(&c));  /* <-- completar el valor esperado */
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE C — Escribir un test propio (ver README.md, Parte 7)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_carrito_lleno() */
void test_carrito_lleno(void) {
    printf("\n[carrito lleno]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 4};
    Producto p2 = {"Carne", 1000, 1};
    Producto p3 = {"Queso", 1500, 1};
    Producto p4 = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    carrito_agregar(&c, p4);
    Producto nuevo_producto = {"Queso", 1500, 1};
    ASSERT_IGUAL(0, carrito_agregar(&c, nuevo_producto));
}

// Tests extra:

void test_carrito_buscar_un_producto(void) {
    printf("\n[buscar producto en carrito]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    ASSERT_IGUAL(0, carrito_buscar(&c, "Leche"));
}

void test_carrito_buscar_producto_no_existente(void) {
    printf("\n[Buscar producto que no existe en carrito]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    Producto p2 = {"Carne", 1000, 1};
    Producto p3 = {"Queso", 1500, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    ASSERT_IGUAL(-1, carrito_buscar(&c, "Pan"));
}

void test_carrito_buscar_producto_en_cantidad(void) {
    printf("\n[Buscar producto en carrito con cantidad]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    Producto p2 = {"Carne", 1000, 1};
    Producto p3 = {"Queso", 1500, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    ASSERT_IGUAL(0, carrito_buscar(&c, "Leche"));
    ASSERT_IGUAL(1, carrito_buscar(&c, "Carne"));
    ASSERT_IGUAL(2, carrito_buscar(&c, "Queso"));
}

void test_agregar_item_con_cantidad_cero(void) {
    printf("\n[Agregar item con cantidad cero]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 0};
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
}

void test_agregar_item_con_cantidad_negativa(void) {
    printf("\n[Agregar item con cantidad negativa]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, -1};
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  main
 * ═══════════════════════════════════════════════════════════════════════════ */

int main(void) {
    printf("=== Tests unitarios ===");
    test_carrito_nuevo();
    test_agregar_uno();
    /* Descomentar a medida que agregues las funciones: */
    test_total_precio_unitario();
    test_total_con_cantidad();
    test_carrito_lleno();     
    test_carrito_buscar_un_producto();
    test_carrito_buscar_producto_no_existente();
    test_carrito_buscar_producto_en_cantidad();
    test_agregar_item_con_cantidad_cero();
    test_agregar_item_con_cantidad_negativa();
    RESUMEN();
    return EXIT_CODE();
}
