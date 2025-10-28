# Sistema de Gestión de Biblioteca en C

Este es un proyecto en C que implementa un sistema básico de gestión de biblioteca. El sistema permite administrar un catálogo de libros, registrar usuarios y gestionar el préstamo y la devolución de libros, utilizando múltiples estructuras de datos combinadas.

## 📚 Características

* **Gestión de Libros:** Agregar nuevos libros al catálogo.
* **Gestión de Usuarios:** Registrar nuevos usuarios en el sistema.
* **Préstamos:** Permitir a un usuario tomar prestado un libro. Si el libro no está disponible, el usuario se añade a una **lista de espera**.
* **Devoluciones:** Registrar la devolución de un libro. Si hay usuarios en lista de espera, el libro se asigna automáticamente al siguiente en la cola.
* **Consultas:** Mostrar el catálogo completo de libros y la lista de usuarios con sus préstamos actuales.
* **Persistencia:** Guardar y cargar automáticamente el estado de la biblioteca (libros y usuarios) en archivos binarios.

