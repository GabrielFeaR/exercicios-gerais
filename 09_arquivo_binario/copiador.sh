#!/bin/bash
# Como usar
# Coloque este copiador_1.sh junto com o correcao.sh no diretorio principal da atividade 
# exemplo: 
#           05_ponteiros/
#              correcao.sh
#              copiador.sh
#              pont_01/
#                 Casos/
#                 Includes/
#                 Gabarito-obj/
#              pont_02/
#                               
# Agora so usar o comando ./copiador_1.sh no diretotio 05_ponteiros
# ATENCAO: ele vai sobre escrever sua main.c e seus .c das bibliotecas, por enquanto so USE NOS EXERCICIOS QUE
# VOCE AINDA NAO FEZ, para alterar o alcance de seu uso modifique a variavel start_dest e end_dest

#################################################################################################
# Define source and destination directories and filenames
#source_dir="" # se quiser alterar o caminho até o correcao.sh altere aqui

source_file="correcao.sh"
include_dir="Includes"
dest_dir="Arq_Bin_" #<coloca o radical da atividade aqui, no diretorio 05_ponteiros seria "pont_"
output_dir="Respostas/Gabriel" #<coloca seu nome aqui
main_file="main.c"

# Define the range of destination directories (em quais exercicios vao ser criados o Respostas/nome)
start_dest=01 
end_dest=05 #coloca a quantidade de atividades
#################################################################################################


# Loop through destination directories
for ((indice = start_dest; indice <= end_dest; indice++)); do
  # Define the full paths for source and destination
  source_path="./$source_file"
  dest_path="${dest_dir}$(printf "%02d" $indice)"  # Concatenate dest_dir and indice Padded with leading zeros


  # Check if the destination directory exists
  if [ -d "$dest_path" ]; then
    # Create the Respostas/JoaoHenrique directory within the destination directory (Respostas/nome)
    mkdir -p "$dest_path/$output_dir"

    # Copy the contents of the Include directory to Respostas/JoaoHenrique (.h do include)
    find "$dest_path/$include_dir" -type f -exec cp {} "$dest_path/$output_dir" \;

    # Rename the copied files in the Respostas/JoaoHenrique directory from .h to .c
    for file in "$dest_path/$output_dir"/*.h; do
      file_deconversao="$file.tmp"
      cp "$file" "$file_deconversao"
      mv "$file_deconversao" "${file%.h}.c"
    done

    # Create a main.c file in the Respostas/JoaoHenrique directory
    echo "// Cole a main do pdf aqui" > "$dest_path/$output_dir/$main_file"

    # Copy the source file to the destination directory (correcao.sh)
    cp "$source_path" "$dest_path/"
    chmod 777 "$source_path"

    echo "Foram copiados '$source_file' e os arquivos do '$include_dir' para '$dest_path/$output_dir'"
  else
    echo "O diretorio '$dest_path/$output_dir' nao existe. Pulando sua copia..."
  fi
done
