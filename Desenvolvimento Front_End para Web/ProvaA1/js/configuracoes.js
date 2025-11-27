// Coordenadas fictícias para a Cidade Aeroviária
const cidadeAeroviaria = [-15.7801, -47.9292]; // Latitude e longitude fictícias (Brasília como exemplo)

// Inicializa o mapa e define o ponto central e o nível de zoom
const map = L.map('map').setView(cidadeAeroviaria, 13); // 'map' é o ID do elemento HTML onde o mapa será renderizado

// Adiciona a camada base do mapa usando tiles do OpenStreetMap
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: 'Mapa da Cidade Aeroviária com Leaflet & OpenStreetMap', // Texto exibido no canto inferior do mapa
}).addTo(map); // Adiciona a camada ao mapa

// Cria um marcador no ponto definido
L.marker(cidadeAeroviaria) // Usa as mesmas coordenadas para posicionar o marcador
    .addTo(map) // Adiciona o marcador ao mapa
    .bindPopup('<b>Rua Sem Número</b><br>Centro da Cidade Aeroviária.') // Define o conteúdo do popup
    .openPopup(); // Abre o popup automaticamente ao carregar o mapa
