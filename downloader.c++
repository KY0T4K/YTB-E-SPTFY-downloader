#include <iostream>
#include <cstdlib>
#include <string>

void downloadYouTubeVideo(const std::string &url)
{
    // Salva o vídeo na pasta "videos" com o nome baseado no título e extensão correta (mp4)
    std::string command = "yt-dlp -f bestvideo+bestaudio --merge-output-format mp4 -o \"videos/%(title)s.%(ext)s\" " + url + " > youtube_log.txt 2>&1";
    std::cout << "Baixando video do YouTube na melhor qualidade: " << url << std::endl;
    int result = system(command.c_str());
    if (result != 0)
    {
        std::cout << "Erro ao executar yt-dlp. Verifique o log youtube_log.txt." << std::endl;
    }
}

void downloadSpotifyMusic(const std::string &url)
{
    // Salva a música na pasta "musicas" com o nome baseado no título e extensão apropriada
    std::string command = "spotdl --output \"musicas/%(title)s.%(ext)s\" " + url + " > spotify_log.txt 2>&1";
    std::cout << "Baixando mysica do Spotify: " << url << std::endl;
    int result = system(command.c_str());
    if (result != 0)
    {
        std::cout << "Erro ao executar spotdl. Verifique o log spotify_log.txt." << std::endl;
    }
}

int main()
{
    int escolha;
    std::string url;

    // Cria as pastas "videos" e "musicas" se não existirem (comando específico para Windows)
    system("if not exist videos mkdir videos");
    system("if not exist musicas mkdir musicas");

    while (true)
    {
        std::cout << "Escolha a opcao:\n";
        std::cout << "1 - Baixar video do YouTube\n";
        std::cout << "2 - Baixar musica do Spotify\n";
        std::cout << "3 - Sair\n";
        std::cout << "Opcao: ";
        std::cin >> escolha;
        std::cin.ignore(); // Limpa buffer

        if (escolha == 3)
        {
            break;
        }

        std::cout << "Insira a URL: ";
        std::getline(std::cin, url);

        if (escolha == 1)
        {
            downloadYouTubeVideo(url);
        }
        else if (escolha == 2)
        {
            downloadSpotifyMusic(url);
        }
        else
        {
            std::cout << "Opcao invalida!" << std::endl;
        }

        // Mensagem de conclusão, pausa e limpeza de tela para retornar ao menu
        std::cout << "Download finalizado. Pressione qualquer tecla para voltar ao menu..." << std::endl;
        system("pause");
        system("cls"); // Limpa a tela no Windows
    }

    return 0;
}
