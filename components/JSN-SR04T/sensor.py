import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, UNIT_CENTIMETER, DEVICE_CLASS_DISTANCE

ultrasonic_sensor_ns = cg.esphome_ns.namespace('jsn-sro4t')

UltrasonicSensor = ultrasonic_sensor_ns.class_('UltrasonicSensor', cg.PollingComponent)

CONFIG_SCHEMA = sensor.sensor_schema(UNIT_CENTIMETER, DEVICE_CLASS_DISTANCE, 1).extend({
    cv.GenerateID(): cv.declare_id(UltrasonicSensor)
}).extend(cv.polling_component_schema('5s'))

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield sensor.register_sensor(var, config)