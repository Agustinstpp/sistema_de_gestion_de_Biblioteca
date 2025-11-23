# Sistema de Gestión de Biblioteca

Breve
-----
Proyecto en C para gestionar una biblioteca simple (agregar usuarios, agregar libros, prestar y devolver). Archivos principales en este repo: `sistema.c` y `biblioteca.h`. Estas instrucciones muestran cómo descargar el repo y compilar/ejecutar usando Dev‑C++ en Windows.

1) Descargar el proyecto
- Con Git:
```bash
git clone https://github.com/Agustinstpp/sistema_de_gestion_de_Biblioteca.git
cd sistema_de_gestion_de_Biblioteca
```
- Sin Git: descargar ZIP desde GitHub (Code → Download ZIP) y extraer en una carpeta.

2) Preparar Dev‑C++
- Asegúrate de usar una versión de Dev‑C++ que incluya MinGW (o instala MinGW‑w64 y añade su `bin` al PATH).
- Abre Dev‑C++.

3) Crear/abrir proyecto en Dev‑C++
- Si tienes un archivo de proyecto `.dev`, ábrelo: Archivo → Abrir proyecto (.dev).
- Si NO tienes `.dev`:
  - Archivo → Nuevo → Proyecto → "Console Application" → elegir "C project" o "Empty project".
  - Guarda el archivo del proyecto en la carpeta del repositorio.

4) Añadir los archivos fuente al proyecto
- Proyecto → Añadir al proyecto → selecciona:
  - `sistema.c`
  - `biblioteca.h`
- Si hay más `.c` o `.h`, añádelos también.
- Asegúrate de que los archivos tengan extensión `.c` (para compilar como C).

5) Opciones del compilador (recomendadas)
- Proyecto → Opciones del proyecto → Parameters / Compiler Options:
  - En Compiler añade: `-std=c11 -Wall -Wextra`
  - En Linker añade (si hace falta funciones matemáticas): `-lm`
- Si usas una carpeta `include`, añade `-Iinclude`.

6) Compilar y ejecutar
- En Dev‑C++ pulsa "Compile" o "Compile & Run" (F9).
- Si compila correctamente, se generará un `*.exe` en la carpeta del proyecto (por ejemplo `sistema.exe` o `biblioteca.exe`).
- Ejecuta desde el IDE o abre la carpeta y ejecuta el `.exe`.

7) Archivos de datos
- El programa usa `libros.dat` y `usuarios.dat` para persistencia. Estos se crearán en la carpeta donde ejecutes el .exe cuando elijas "Guardar y Salir".
