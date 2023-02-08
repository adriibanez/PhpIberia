<?php

namespace app\iberia\repo;

class OcupacionRepo
{
    public function mostarOcupacion(string $codigo, string $fecha): array
    {
        $sql = 'SELECT *
        FROM vuelos
        WHERE codigo = :codigo 
        AND fecha = :fecha';

        require_once __DIR__ . './../../core/conexionBd.inc';
        $ocupacion = [];
        try {
            $con = (new  \ConexionBd())->getConexion();
            $stn = $con->prepare($sql);
            $stn->bindValue(':codigo', $codigo);
            $stn->bindValue(':fecha', $fecha);
            $stn->execute();
            $ocupacion = $stn->fetchAll(\PDO::FETCH_ASSOC);

            return $ocupacion;
        } catch (\PDOException $ex) {
            throw $ex;
        } finally {
            unset($stn);
            unset($con);
        }
    }
}
